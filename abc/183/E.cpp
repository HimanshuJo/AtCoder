#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  for (auto& si : s) {
    cin >> si;
  }
  vector dp(4, vector(h, vector(w, mint(0))));
  dp[0][0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (s[i][j] != '#') {
        if (i) {
          for (int k = 0; k < 4; ++k) {
            dp[1][i][j] += (k == 1 ? 2 : 1) * dp[k][i - 1][j];
          }
        }
        if (j) {
          for (int k = 0; k < 4; ++k) {
            dp[2][i][j] += (k == 2 ? 2 : 1) * dp[k][i][j - 1];
          }
        }
        if (i && j) {
          for (int k = 0; k < 4; ++k) {
            dp[3][i][j] += (k == 3 ? 2 : 1) * dp[k][i - 1][j - 1];
          }
        }
      }
    }
  }
  mint c = 0;
  for (int k = 0; k < 4; ++k) {
    c += dp[k][h - 1][w - 1];
  }
  cout << c.val() << "\n";
  return 0;
}