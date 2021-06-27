#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a = ReadArray(n), b = ReadArray(n), p = ReadArray(n), ip(n);
  for (int i = 0; i < n; ++i) {
    --p[i];
    ip[p[i]] = i;
  }

  std::vector<std::pair<int, int>> ai(n);
  for (int i = 0; i < n; ++i) {
    ai[i] = std::make_pair(a[i], i);
  }
  std::sort(ai.begin(), ai.end());

  bool possible = true;
  std::vector<std::pair<int, int>> operations;

  for (int i = 0; i < n && possible; ++i) {
    // for (int j = 0; j < n; ++j) {
    //   std::cout << "j = " << j
    //     << ", a[" << j << "] = " << a[j]
    //     << ", b[" << p[j] << "] = " << b[p[j]]
    //     << ", p[" << j << "] = " << p[j]
    //     << ", ip[" << j << "] = " << ip[j] << "\n"; 
    // }
    // std::cout << "\n";

    int j = ai[i].second;
    if (p[j] != j) {
      if (b[p[j]] >= a[j]) {
        possible = false;
      } else {
        int k = ip[j];
        if (b[p[k]] >= a[k]) {
          possible = false;
        } else {
          // std::swap(b[p[j]], b[p[k]]);
          ip[j] = j;
          ip[p[j]] = k;
          std::swap(p[j], p[k]);
          operations.emplace_back(j, k);
        }
      }
    }
  }

  if (possible) {
    std::cout << operations.size() << "\n";
    for (const auto& [first, second] : operations) {
      std::cout << first + 1 << " " << second + 1 << "\n";
    }
  } else {
    std::cout << -1 << "\n";
  }

  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  std::vector<T> array(size);
  for (auto& element : array) {
    std::cin >> element;
  }
  return array;
}
