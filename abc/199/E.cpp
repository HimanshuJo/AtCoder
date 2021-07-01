#include <bits/stdc++.h>
using namespace std;
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, m;
  cin >> n >> m;
  vector<tuple<int, int, int>> xyz(m);
  for (auto& [x, y, z] : xyz) {
    cin >> x >> y >> z;
  }
  vector<vector<pair<int, int>>> yz(n + 1);
  for (auto [x, y, z] : xyz) {
    yz[x].emplace_back(y, z);
  }
  vector<int64_t> dp(1 << n);
  dp[0] = 1;
  auto good = [&] (int mask) -> bool {
    for (auto [y, z] : yz[__builtin_popcount(mask)]) {
      if (__builtin_popcount(mask & ((1 << y) - 1)) > z) {
        return false;
      }
    }
    return true;
  };
  for (int mask = 1; mask < (1 << n); ++mask) {
    for (int bit = 0; bit < n; ++bit) {
      if (mask & (1 << bit)) {
        if (good(mask)) {
          dp[mask] += dp[mask ^ (1 << bit)];
        }
      }
    }
  }
  cout << dp[(1 << n) - 1] << "\n";
  return 0;
}