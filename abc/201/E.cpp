#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int64_t>>> g(n);
  for (int e = 0; e < n - 1; ++e) {
    int ui, vi;
    int64_t wi;
    cin >> ui >> vi >> wi;
    --ui, --vi;
    g[ui].emplace_back(vi, wi);
    g[vi].emplace_back(ui, wi);
  }
  int64_t mod = 1'000'000'007;
  int64_t sum = 0;
  vector<int> visited(n);
  function<pair<int64_t, int64_t>(int, int)> dfs \
      = [&] (int vertex, int bit) -> pair<int64_t, int64_t> {
    visited[vertex] = true;
    int64_t odd = 0, even = 1;
    for (auto [neighbour, weight] : g[vertex]) {
      if (!visited[neighbour]) {
        auto [nodd, neven] = dfs(neighbour, bit);
        if (weight & (1ll << bit)) {
          sum += odd * nodd;
          sum %= mod;

          sum += even * neven;
          sum %= mod;

          odd += neven;
          even += nodd;
        } else {
          sum += odd * neven;
          sum %= mod;

          sum += even * nodd;
          sum %= mod;

          odd += nodd;
          even += neven;
        }
      }
    }
    // cout << "vertex = " << vertex << ", bit = " << bit << ", odd = " << odd << ", even = " << even << "\n";
    return {odd, even};
  };
  auto solve = [&] (int bit) -> int64_t {
    visited.assign(n, false);
    sum = 0;
    dfs(0, bit);
    for (int _ = 0; _ < bit; ++_) {
      sum <<= 1;
      sum %= mod;
    }
    return sum;
  };
  int64_t ans = 0;
  for (int bit = 0; bit < 60; ++bit) {
    ans += solve(bit);
    ans %= mod;
  }
  cout << ans << "\n";
  return 0;
}
