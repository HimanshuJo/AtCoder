#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> lr(k);
  for (auto& [l, r] : lr) {
    cin >> l >> r;
  }
  vector dp(n, mint(0)), psdp(n + 1, mint(0));
  psdp[1] = dp[0] = 1;
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      int l = i - lr[j].first + 1;
      int r = i - lr[j].second;
      dp[i] += psdp[max(l, 0)] - psdp[max(r, 0)];
    }
    psdp[i + 1] = psdp[i] + dp[i];
  }
  for (auto dpi : dp) {
    cerr << dpi.val() << " ";
  }
  cerr << "\n";
  cout << dp[n - 1].val() << "\n";
  return 0;
}