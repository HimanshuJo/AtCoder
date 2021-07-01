#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;

  auto good = [&] (int c, int b) -> bool {
    while (c) {
      if (c % b == 7) {
        return false;
      } else {
        c /= b;
      }
    }
    return true;
  };

  int c = 0;
  for (int i = 1; i <= n; ++i) {
    if (good(i, 8) && good(i, 10)) {
      ++c;
    }
  }
  std::cout << c << "\n";

  return 0;
}
