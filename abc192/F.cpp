#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t n, x;
  cin >> n >> x;
  vector<int64_t> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  int64_t min_time = 2e18;
  for (int size = 1; size <= n; ++size) {
    // subset size, remainder
    vector<vector<int64_t>> dp(size + 1, vector<int64_t>(size, -1));
    dp[0][0] = 0;
    for (auto ai : a) {
      for (int ssize = size - 1; ssize >= 0; --ssize) {
        for (int rem = 0; rem < size; ++rem) {
          if (dp[ssize][rem] != -1) {
            dp[ssize + 1][(rem + ai) % size] = \
              max(dp[ssize + 1][(rem + ai) % size],
                dp[ssize][rem] + ai);
          }
        }
      }
    }
    int64_t best = dp[size][x % size];
    if (best != -1) {
      min_time = min(min_time, (x - best) / size);
    }
  }
  cout << min_time << "\n";
  return 0;
}
