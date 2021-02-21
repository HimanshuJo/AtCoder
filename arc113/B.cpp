#include <bits/stdc++.h>
using namespace std;
int64_t power(int64_t base, int64_t exponent, int64_t mod) {
  base %= mod;
  int64_t result = base ? 1 : 0;
  while (exponent) {
    if (exponent & 1) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    exponent >>= 1;
  }
  return result;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t a, b, c;
  cin >> a >> b >> c;
  cout << power(a, power(b, c, 2520), 10) << "\n";
  return 0;
}
