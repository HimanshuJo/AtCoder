#include <bits/stdc++.h>
using namespace std;

long double dp[101][101][101];

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  for (int i = 1, ii = 99; i <= 100; ++i, --ii)
    for (int j = 1, jj = 99; j <= 100; ++j, --jj)
      for (int k = 1, kk = 99; k <= 100; ++k, --kk)
        dp[i][j][k] = 1 + (ii * dp[i - 1][j][k] + jj * dp[i][j - 1][k] + kk * dp[i][j][k - 1]) / (ii + jj + kk);

  int a, b, c;
  cin >> a >> b >> c;
  cout << fixed << setprecision(10) << dp[100 - a][100 - b][100 - c] << "\n";

  return 0;
}
