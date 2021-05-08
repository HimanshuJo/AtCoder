#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1'000'000'007;
int64_t pwr(int64_t base, int64_t power, int64_t modulo = mod) {
  if (power < 0) {
    return 0;
  }
  int64_t result = 1;
  while (power) {
    if (power & 1) {
      result *= base;
      result %= modulo;
    }
    base *= base;
    base %= modulo;
    power >>= 1;
  }
  return result;
}
int64_t inv(int64_t number, int64_t modulo = mod) {
  return pwr(number, modulo - 2, modulo);
} 
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  int64_t k;
  cin >> s >> k;
  const int64_t n = s.length();
  int64_t q = count(s.begin(), s.end(), '?');
  int64_t p0 = pwr(2, k * q), p1 = pwr(2, k * q - 1), p2 = pwr(2, k * q - 2);
  auto c01 = [&] (char c0, char c1) -> int64_t {
    if (c0 == '0' && c1 == '1') {
      return p0 * k;
    } else if (c0 == '0' && c1 == '?') {
      return p1 * k;
    } else if (c0 == '?' && c1 == '1') {
      return p1 * k;
    } else if (c0 == '?' && c1 == '?') {
      return p2 * k;
    } else {
      return 0;
    }
  };
  auto c10 = [&] (char c0, char c1) -> int64_t {
    if (c0 == '1' && c1 == '0') {
      return p0 * k;
    } else if (c0 == '1' && c1 == '?') {
      return p1 * k;
    } else if (c0 == '?' && c1 == '0') {
      return p1 * k;
    } else if (c0 == '?' && c1 == '?') {
      return p2 * k;
    } else {
      return 0;
    }
  };
  auto cnt01 = [&] () -> int64_t {
    int64_t a = 0;
    for (int i = 0; i + 1 < n; ++i) {
      a += c01(s[i], s[i + 1]);
      a %= mod;
    }
    a += c01(s[n - 1], s[0]);
    a %= mod;
    return a;
  };
  auto cnt10 = [&] () -> int64_t {
    int64_t a = 0;
    for (int i = 0; i + 1 < n; ++i) {
      a += c10(s[i], s[i + 1]);
      a %= mod;
    }
    a += c10(s[n - 1], s[0]);
    a %= mod;
    return a;
  };
  if (s[0] == '0') {
    // count 01
    cout << cnt01() << "\n";
  } else if (s[0] == '1') {
    // count 10
    cout << cnt10() << "\n";
  } else {
    // count 01 and 10
    cout << (inv(2) * (cnt01() + cnt10())) % mod << "\n";
  }
  return 0;
}