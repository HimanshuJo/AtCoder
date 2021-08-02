#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(),cerr.tie(0);
  int n;
  cin >> n;
  vector<int> h(n);
  for (auto& hi : h) {
    cin >> hi;
  }
  vector<vector<int>> cnk(n + 1, vector<int>(n + 1));
  for (int i = 0; i <= n; ++i) {
    cnk[i][0] = cny[i][i] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      cnk[i][j] = cnk[i - 1][j - 1] + cnk[i - 1][j];
      cnk[i][j] %= mod;
    }
  }

  // [l, r]
  auto cnt = [&] (int l, int r) -> int {

  };

  vector<pair<int, int>> wl;
  for (int i = 0, j = 0; i < n; ++i) {
    if (h[i] == h[i + 1]) {
      wl.emplace_back(cnt(j, i), i - j + 1);
      j = i + 1;
    }
  }
  int64_t W = 1, L = 0;
  for (auto [w, l] : wl) {
    W *= w;
    W %= mod;
    W *= cnk[L + l][l];
    W %= mod;
    L += l;
  }
  cout << W << "\n";

  // h[i] < h[i+1] => h[i] must be cut after h[i+1]

  //    /\
  //   /  \  /\    /
  //  /    \/  \  /
  // /          \/

  // L R
  // cnk[L + R][L] * 1 * 1

  // X Y
  // cnk[X + Y][X] * A(X) * A(Y)

  // 2 1 2
  // 1 3 2
  // 3 1 2

  // 2 1 1 2
  // 1 4 2 3
  // 1 4 3 2
  // 4 1 2 3
  // 4 1 3 2
  // 1 2 4 3
  // 4 3 1 2

  // dp[l][r] = sum(f(dp[l][m], dp[m][r]) for m in range(l, r))
  return 0;
}