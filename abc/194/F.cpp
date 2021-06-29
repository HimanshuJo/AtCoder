#include <bits/stdc++.h>
using namespace std;

#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif

const int mod = 1'000'000'007;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  string n; int k;
  cin >> n >> k;

  auto convert = [&] (char c) -> int {
    if (isdigit(c)) {
      return c - '0';
    } else {
      return c - 'A' + 10;
    }
  };

  const int m = n.length();
  vector<int> cnt(m + 1);
  for (int i = 0; i < m; ++i) {
    cnt[i + 1] = cnt[i] | (1 << convert(n[i]));
  }

  vector<vector<int64_t>> dp(m + 1, vector<int64_t>(17));
  // dp[0][0] = 1;

  for (int i = 0; i < m; ++i) {
    // smaller prefix
    for (int j = 0; j <= k; ++j) {
      // old digit
      dp[i + 1][j] += j * dp[i][j];
      dp[i + 1][j] %= mod;
      // new digit
      if (j < k) {
        dp[i + 1][j + 1] += (16 - j) * dp[i][j];
        dp[i + 1][j + 1] %= mod;
      }
    }
    // equal prefix
    for (int j = i ? 0 : 1; j < convert(n[i]); ++j) {
      if (cnt[i] & (1 << j)) {
        ++dp[i + 1][__builtin_popcount(cnt[i])];
        dp[i + 1][__builtin_popcount(cnt[i])] %= mod;
      } else {
        ++dp[i + 1][__builtin_popcount(cnt[i]) + 1];
        dp[i + 1][__builtin_popcount(cnt[i]) + 1] %= mod;
      }
    }
    // no prefix
    if (i) {
      dp[i + 1][1] += 15;
      dp[i + 1][1] %= mod;
    }
  }

  // = n
  ++dp[m][__builtin_popcount(cnt[m])];
  dp[m][__builtin_popcount(cnt[m])] %= mod;

  cout << dp[m][k] << "\n";

  return 0;
}