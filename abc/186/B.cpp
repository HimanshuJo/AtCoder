#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int h, w;
  std::cin >> h >> w;
  std::vector<std::vector<int>> a(h, std::vector<int>(w));
  for (auto& ai : a) {
    for (auto& aij : ai) {
      std::cin >> aij;
    }
  }

  int m = std::numeric_limits<int>::max();
  for (const auto& ai : a) {
    for (auto aij : ai) {
      m = std::min(m, aij);
    }
  }

  int s = 0;
  for (const auto& ai : a) {
    for (auto aij : ai) {
      s += aij - m;
    }
  }
  std::cout << s << "\n";

  return 0;
}
