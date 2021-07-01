#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int l;
  std::cin >> l;
  int64_t a = 1;
  for (int i = 1; i <= 11; ++i) {
    a *= l - i;
    a /= i;
  }
  std::cout << a << "\n";

  return 0;
}
