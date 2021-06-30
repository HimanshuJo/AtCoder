#include <bits/stdc++.h>
using namespace std;

const int inf = numeric_limits<int>::max();
const int64_t inf64_t = numeric_limits<int64_t>::max();

struct Ball {
  int64_t x, c;
};

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n;
  cin >> n;

  vector<Ball> balls(n);
  for (auto& ball : balls) {
    cin >> ball.x >> ball.c;
  }

  vector<int64_t> l(n + 1, inf), r(n + 1, -inf);
  l[0] = r[0] = 0;
  for (auto ball : balls) {
    l[ball.c] = min(l[ball.c], ball.x);
    r[ball.c] = max(r[ball.c], ball.x);
  }

  vector<vector<int64_t>> dp(2, vector<int64_t>(n + 1, inf64_t));
  dp[0][0] = dp[1][0] = 0;
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    if (l[i] != inf && r[i] != -inf) {
      dp[0][i] = min(dp[0][j] + abs(l[j] - r[i]) + abs(r[i] - l[i]),
                     dp[1][j] + abs(r[j] - r[i]) + abs(r[i] - l[i]));
      dp[1][i] = min(dp[0][j] + abs(l[j] - l[i]) + abs(l[i] - r[i]),
                     dp[1][j] + abs(r[j] - l[i]) + abs(l[i] - r[i]));
      j = i;
    }
  }

  cout << min(dp[0][j] + abs(l[j]), dp[1][j] + abs(r[j])) << "\n";

  return 0;
}
