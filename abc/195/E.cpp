#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n;
  string s, x;
  cin >> n >> s >> x;
  reverse(s.begin(), s.end());
  reverse(x.begin(), x.end());

  vector<vector<int>> dp(7, vector<int>(n + 1, -1));
  // -1 -- unreachable, 0 -- Aoki, 1 -- Takahashi
  dp[0][0] = 1;
  for (int rem = 1; rem < 7; ++rem) {
    dp[rem][0] = 0;
  }

  for (int p = 1, i = 0; i < n; ++i, p = (10 * p) % 7) {
    for (int rem = 0; rem < 7; ++rem) {
      int new_rem = (rem + p * (s[i] - '0')) % 7;
      if (x[i] == 'A') {
        if (dp[rem][i] == 0) {
          dp[rem][i + 1] = 0;
          dp[new_rem][i + 1] = 0;
        }
      } else {
        if (dp[rem][i] == 1) {
          dp[rem][i + 1] = 1;
          dp[new_rem][i + 1] = 1;
        }
      }
    }
    for (int rem = 0; rem < 7; ++rem) {
      if (dp[rem][i + 1] == -1) {
        if (x[i] == 'A') {
          dp[rem][i + 1] = 1;
        } else {
          dp[rem][i + 1] = 0;
        }
      }
    }
  }

  cout << (dp[0][n] ? "Takahashi" : "Aoki") << "\n";

  return 0;
}
