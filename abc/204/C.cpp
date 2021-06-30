#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
  }
  int c = 0;
  for (int s = 0; s < n; ++s) {
    vector<bool> u(n);
    function<int(int)> dfs = [&] (int v) -> int {
      u[v] = true;
      int r = 1;
      for (auto w : g[v]) {
        if (!u[w]) {
          r += dfs(w);
        }
      }
      return r;
    };
    c += dfs(s);
  }
  cout << c << "\n";
  return 0;
}