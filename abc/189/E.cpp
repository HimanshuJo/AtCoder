#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct Point {
  int64_t x, y;
};

// operation types
const int kRotateClockwise = 1;
const int kRotateCounterclockwise = 2;
const int kReflectHorizontal = 3;
const int kReflectVertical = 4;

struct Operation {
  int type;
  int64_t position;
};

struct Query {
  int operation_id;
  int point_id;
  int id;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int points_count;
  std::cin >> points_count;
  std::vector<Point> points(points_count);
  for (auto& point : points) {
    std::cin >> point.x >> point.y;
  }

  int operations_count;
  std::cin >> operations_count;
  std::vector<Operation> operations(operations_count);
  for (auto& operation : operations) {
    std::cin >> operation.type;
    if (operation.type == kReflectVertical ||
        operation.type == kReflectHorizontal) {
      std::cin >> operation.position;
    }
  }

  int queries_count;
  std::cin >> queries_count;
  std::vector<Query> queries(queries_count);
  for (int query_id = 0; query_id < queries_count; ++query_id) {
    auto& query = queries[query_id];
    query.id = query_id;
    std::cin >> query.operation_id >> query.point_id;
    --query.point_id;
  }

  std::sort(queries.begin(), queries.end(),
    [] (const Query& first, const Query& second) -> bool {
      return first.operation_id < second.operation_id;
    });

  std::vector<Point> answers(queries_count);

  // 1 = x, -1 = -x, 2 = y, -2 = -y
  int xs = 1, ys = 2;
  int64_t px = 0, py = 0;

  int op_id = 0;
  for (const auto& query : queries) {
    while (query.operation_id > op_id) {
      const auto& operation = operations[op_id];
      if (operation.type == kRotateClockwise) {
        std::tie(xs, ys) = std::make_pair(ys, -xs);
        std::tie(px, py) = std::make_pair(py, -px);
      } else if (operation.type == kRotateCounterclockwise) {
        std::tie(xs, ys) = std::make_pair(-ys, xs);
        std::tie(px, py) = std::make_pair(-py, px);
      } else if (operation.type == kReflectHorizontal) {
        px = 2 * operation.position - px;
        xs = -xs;
      } else {  // operation.type == kReflectVertical
        py = 2 * operation.position - py;
        ys = -ys;
      }
      ++op_id;
    }

    if (xs == 1) {
      answers[query.id].x = points[query.point_id].x + px;
    } else if (xs == 2) {
      answers[query.id].x = points[query.point_id].y + px;
    } else if (xs == -1) {
      answers[query.id].x = -points[query.point_id].x + px;
    } else {  // xs == -2
      answers[query.id].x = -points[query.point_id].y + px;
    }

    if (ys == 1) {
      answers[query.id].y = points[query.point_id].x + py;
    } else if (ys == 2) {
      answers[query.id].y = points[query.point_id].y + py;
    } else if (ys == -1) {
      answers[query.id].y = -points[query.point_id].x + py;
    } else {  // ys == -2
      answers[query.id].y = -points[query.point_id].y + py;
    }
  }

  // this dp can be simplified to operations on 3x3 matrices
  // watch https://www.twitch.tv/anandoza for details

  for (const auto& answer : answers) {
    std::cout << answer.x << " " << answer.y << "\n";
  }

  return 0;
}
