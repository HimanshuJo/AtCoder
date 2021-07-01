#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> u(n);
  vector<vector<int>> cc;
  function<void(int)> dfs = [&] (int v) -> void {
    u[v] = true;
    cc.back().push_back(v);
    for (auto w : g[v]) {
      if (!u[w]) {
        dfs(w);
      }
    }
  };
  for (int v = 0; v < n; ++v) {
    if (!u[v]) {
      cc.emplace_back();
      dfs(v);
    }
  }
  int64_t cnt = 1;
  vector clr(3, vector(n, 0));
  for (auto c : cc) {
    int r = 0;
    function<void(int)> dp = [&] (int i) {
      if (i == int(c.size())) {
        ++r;
      } else {
        for (int k = 0; k < 3; ++k) {
          if (!(clr[k][c[i]])) {
            for (auto v : g[c[i]]) {
              ++clr[k][v];
            }
            dp(i + 1);
            for (auto v : g[c[i]]) {
              --clr[k][v];
            }
          }
        }
      }
    };
    dp(0);
    cnt *= r;
  }
  cout << cnt << "\n";
  return 0;
}