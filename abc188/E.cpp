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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  const auto a = ReadArray(n);
  vector<vector<int>> graph(n);
  while (m--) {
    int xi, yi;
    cin >> xi >> yi;
    --xi, --yi;
    graph[xi].push_back(yi);
  }

  vector<int> min_ancestor_price(n, numeric_limits<int>::max());
  int best_price_difference = numeric_limits<int>::min();
  for (int i = 0; i < n; ++i) {
    best_price_difference = max(best_price_difference, a[i] - min_ancestor_price[i]);
    min_ancestor_price[i] = min(min_ancestor_price[i], a[i]);
    for (auto j : graph[i]) {
      min_ancestor_price[j] = min(min_ancestor_price[j], min_ancestor_price[i]);
    }
  }

  cout << best_price_difference << "\n";

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
