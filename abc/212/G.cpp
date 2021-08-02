#include <bits/stdc++.h>
using namespace std;
const int mod = 998'244'353;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int64_t p, q;
  cin >> p;
  q = p - 1;
  // https://cp-algorithms.com/algebra/phi-function.html
  auto phi = [&] (int64_t n) -> int64_t {
    int64_t result = n;
    for (int64_t i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        while (n % i == 0)
          n /= i;
        result -= result / i;
      }
    }
    if (n > 1)
      result -= result / n;
    return result % mod;
  };
  int64_t ans = 1;
  for (int64_t d = 1; d * d <= q; ++d) {
    if (q % d == 0) {
      ans += d * phi(d);
      ans %= mod;
      if (d * d < q) {
        ans += ((q / d) % mod) * phi(q / d);
        ans %= mod;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}