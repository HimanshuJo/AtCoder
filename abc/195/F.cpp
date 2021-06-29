#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int64_t a, b;
  cin >> a >> b;

  const int n = b - a + 1;
  vector<vector<bool>> g(n, vector<bool>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (gcd(a + i, a + j) == 1) {
        g[i][j] = true;
      }
    }
  }

  // TODO: change to sieve
  const int k = 20;
  vector<int> p = { 2,  3,  5,  7, 11, 13, 17, 19, 23, 29,
                   31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

  vector<int> pd(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      if ((a + i) % p[j] == 0) {
        pd[i] |= 1 << j;
      }
    }
  }

  vector<vector<int64_t>> dp(2, vector<int64_t>(1 << k));
  dp[0][0] = 1;

  for (int i = 0; i < n; ++i) {
    for (int prime_mask = 0; prime_mask < (1 << k); ++prime_mask) {
      // take
      if (!(prime_mask & pd[i])) {
        dp[(i + 1) & 1][prime_mask | pd[i]] += dp[i & 1][prime_mask];
      }
      // skip
      dp[(i + 1) & 1][prime_mask] += dp[i & 1][prime_mask];
    }
    dp[i & 1].assign(1 << k, 0);
  }

  cout << accumulate(dp[n & 1].begin(), dp[n & 1].end(), int64_t(0)) << "\n";

  return 0;
}