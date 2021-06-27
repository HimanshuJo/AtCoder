#include <bits/stdc++.h>
using namespace std;
const int64_t kInf = numeric_limits<int64_t>::max();
int64_t euclid_gcd(int64_t first, int64_t second) {
  int64_t temporary;
  while (second) {
    temporary = first % second;
    first = second;
    second = temporary;
  }
  return std::abs(first);
}
std::pair<int64_t, int64_t> extended_euclid(int64_t first, int64_t second) {
  int64_t first_coefficient = 1, second_coefficient = 0,
    next_first_coefficient = 0, next_second_coefficient = 1, temporary;
  while (second) {
    const auto [quotient, remainder] = std::div(first, second);
    temporary = first_coefficient;
    first_coefficient = next_first_coefficient;
    next_first_coefficient = temporary - quotient * next_first_coefficient;
    temporary = second_coefficient;
    second_coefficient = next_second_coefficient;
    next_second_coefficient = temporary - quotient * next_second_coefficient;
    temporary = first;
    first = second;
    second = remainder;
  }
  if (first > 0) {
    return {first_coefficient, second_coefficient};
  } else {
    return {-first_coefficient, -second_coefficient};
  }
}
int64_t euclid_inverse(int64_t number, int64_t modulo) {
  assert(euclid_gcd(number, modulo) == 1);
  return (extended_euclid(number, modulo).first + modulo) % modulo;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t t;
  cin >> t;
  while (t--) {
    int64_t x, y, p, q;
    cin >> x >> y >> p >> q;
    int64_t best = kInf;
    // takahashi was awake and train arrives
    for (int64_t qq = 0; qq < q; ++qq) {
      int64_t m = p + q;
      int64_t a = (p + qq - x) % m;
      if (a < 0) a += m;
      int64_t b = (2 * x + 2 * y) % m;
      if (b < 0) b += m;
      int64_t g = euclid_gcd(b, m);
      if (a % g == 0) {
        b /= g;
        a /= g;
        m /= g;
        int64_t n = (euclid_inverse(b, m) * a) % m;
        best = min(best, n * (2 * x + 2 * y) + x);
      }
    }
    // train arrived and takahashi awakes
    for (int64_t yy = 0; yy < y; ++yy) {
      int64_t m = p + q;
      int64_t a = (p - x - yy) % m;
      if (a < 0) a += m;
      int64_t b = (2 * x + 2 * y) % m;
      if (b < 0) b += m;
      int64_t g = euclid_gcd(b, m);
      if (a % g == 0) {
        b /= g;
        a /= g;
        m /= g;
        int64_t n = (euclid_inverse(b, m) * a) % m;
        best = min(best, n * (2 * x + 2 * y) + x + yy);
      }
    }
    if (best == kInf) {
      cout << "infinity\n";
    } else {
      cout << best << "\n";
    }
  }
  return 0;
}
