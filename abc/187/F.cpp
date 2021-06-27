#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, e;
  cin >> n >> e;

  vector<vector<bool>> g(n, vector<bool>(n));
  while (e--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = true;
  }

  vector<bool> c(1 << n, true);
  for (int m = 0; m < (1 << n); ++m) {
    for (int i = 0; i < n && c[m]; ++i) {
      if (m & (1 << i)) {
        for (int j = i + 1; j < n && c[m]; ++j) {
          if (m & (1 << j)) {
            if (!g[i][j]) {
              c[m] = false;
            }
          }
        }
      }
    }
  }

  vector<int> dp(1 << n, n);
  dp[0] = 0;
  for (int m = 0; m < (1 << n); ++m) {
    for (int s = m; s; s = (s - 1) & m) {
      if (c[s]) {
        dp[m] = min(dp[m], dp[m ^ s] + 1);
      }
    }
  }
  cout << dp[(1 << n) - 1] << "\n";

  return 0;
}
