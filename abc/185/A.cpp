#include <algorithm>
#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int a1, a2, a3, a4;
  std::cin >> a1 >> a2 >> a3 >> a4;
  std::cout << std::min({a1, a2, a3, a4}) << "\n";

  return 0;
}
