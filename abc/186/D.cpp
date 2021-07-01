#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }

  std::sort(a.begin(), a.end());

  int64_t sd = 0;
  for (int i = 1; i < n; ++i) {
    sd += i * 1ll * (a[i] - a[i - 1]) * 1ll * (n - i);
  }
  std::cout << sd << "\n";

  return 0;
}
