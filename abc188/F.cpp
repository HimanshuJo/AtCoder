#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

template <typename T>
void PrintArray(const std::vector<T>& array, std::ostream& out_stream = std::cout,
                bool size = false, char element_separator = ' ', char end = '\n');

unordered_map<int64_t, int64_t> answers;

int64_t solve(int64_t x, int64_t y) {
  if (!answers.count(y)) {
    if (x >= y) {
      answers[y] = x - y;
    } else {  // x < y
      int64_t answer = y - x;

      // use /2 operation at some point
      if (y & 1) {
        // [(y - 1) / 2, (y + 1) / 2] - 2 ops
        int64_t lo = y >> 1;
        int64_t hi = lo + 1;
        answer = min(answer, 2 + min(solve(x, lo), solve(x, hi)));
      } else {
        // [y / 2] - 1 op
        answer = min(answer, 1 + solve(x, y >> 1));
      }

      answers[y] = answer;
    }
  }

  return answers[y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t x, y;
  cin >> x >> y;
  cout << solve(x, y) << "\n";

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

template <typename T>
void PrintArray(const std::vector<T>& array, std::ostream& out_stream,
                bool size, char element_separator, char end) {
  if (size) {
    out_stream << array.size() << end;
  }
  for (const auto& element : array) {
    out_stream << element << element_separator;
  }
  out_stream << end;
}
