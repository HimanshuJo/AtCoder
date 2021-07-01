#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto& ci : c) {
    cin >> ci;
  }
  const int r = 0;
  vector<vector<int>> g(n);
  for (int _ = 1; _ < n; ++_) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const int maxc = 100'000;
  vector<int> f(maxc + 1);
  set<int> good;
  vector<bool> u(n);
  function<void(int)> dfs = [&] (int v) {
    u[v] = true;
    if (!f[c[v]]) {
      good.insert(v);
    }
    ++f[c[v]];
    for (auto w : g[v]) {
      if (!u[w]) {
        dfs(w);
      }
    }
    --f[c[v]];
  };
  dfs(r);
  for (auto goodie : good) {
    cout << goodie + 1 << "\n";
  }
  return 0;
}
