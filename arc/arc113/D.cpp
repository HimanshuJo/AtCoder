#include <bits/stdc++.h>
using namespace std;
const int64_t mod = 998'244'353;
int64_t power(int64_t base, int64_t exponent) {
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
  int64_t n, m, k, count = 0;
  cin >> n >> m >> k;
  if (n > 1 && m > 1) {
    vector<int64_t> pow2 = {0};
    for (int64_t k0 = 1; k0 <= k; ++k0) {
      pow2.push_back(power(k0, m) - power(k0 - 1, m));
      if (pow2[k0] < 0) {
        pow2[k0] += mod;
      }
    }
    for (int64_t k0 = 1; k0 <= k; ++k0) {
      count += power(k0, n) * pow2[k - k0 + 1];
      count %= mod;
    }
  } else {
    int64_t nm = n * m;
    vector<int64_t> pow2 = {0};
    for (int64_t k0 = 1; k0 <= k; ++k0) {
      pow2.push_back(power(k0, nm) - power(k0 - 1, nm));
      if (pow2[k0] < 0) {
        pow2[k0] += mod;
      }
    }
    for (int64_t k0 = 1; k0 <= k; ++k0) {
      count += pow2[k0];
      count %= mod;
    }
  }
  cout << count << "\n";
  return 0;
}
