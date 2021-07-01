#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, w;
  std::cin >> n >> w;
  std::cout << n / w << "\n";

  return 0;
}
