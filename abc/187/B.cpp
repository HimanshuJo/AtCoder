#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

struct Point {
  int x, y;
  friend istream& operator>>(istream& in_stream, Point& point);
};

long double Slope(Point first, Point second) {
  if (first.x > second.x) {
    swap(first, second);
  }
  if (first.x == second.x) {
    return numeric_limits<long double>::max();
  }
  return (second.y - first.y) * 1. / (second.x - first.x);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const auto points = ReadArray<Point>();
  const int point_count = points.size();

  int answer = 0;
  for (int i = 0; i < point_count; ++i) {
    for (int j = i + 1; j < point_count; ++j) {
      auto slope = Slope(points[i], points[j]);
      if (-1 <= slope && slope <= 1) {
        ++answer;
      }
    }
  }
  cout << answer;

  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  std::vector<T> array(size);
  for (auto& element : array) {
    in_stream >> element;
  }
  return array;
}

istream& operator>>(istream& in_stream, Point& point) {
  in_stream >> point.x >> point.y;
  return in_stream;
}
