#include <iostream>
#include <tuple>

int64_t gcd (int64_t a, int64_t b) {
  while (b) {
    a %= b;
    std::swap(a, b);
  }
  return a;
}

int64_t xgcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  x = 1, y = 0;
  int64_t x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    int64_t q = a1 / b1;
    std::tie(x, x1) = std::make_tuple(x1, x - q * x1);
    std::tie(y, y1) = std::make_tuple(y1, y - q * y1);
    std::tie(a1, b1) = std::make_tuple(b1, a1 - q * b1);
  }
  return a1;
}

int64_t gcdinv(int64_t a, int64_t m) {
  int64_t x, y;
  int64_t g = xgcd(a, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    return (x % m + m) % m;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int64_t t;
  std::cin >> t;
  while (t --> 0) {
    int64_t n, s, k;
    std::cin >> n >> s >> k;
    int64_t g = gcd(gcd(k, n), s);
    k /= g;
    s /= g;
    n /= g;
    int64_t inv = gcdinv(k, n);
    std::cout << ((inv == -1) ? -1 : (((n - s) * inv) % n)) << "\n";
  }

  return 0;
}
