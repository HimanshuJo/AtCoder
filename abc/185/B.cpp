#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m, t;
  std::cin >> n >> m >> t;
  int c = n, k = 0;
  bool p = true; 
  while (m --> 0) {
    int a, b;
    std::cin >> a >> b;
    c -= a - k;
    if (c <= 0) {
      p = false;
    }
    c += b - a;
    if (c > n) {
      c = n;
    }
    k = b;
  }
  c -= t - k;
  if (c <= 0) {
    p = false;
  }
  std::cout << (p ? "Yes" : "No") << "\n";

  return 0;
}
