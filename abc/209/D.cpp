#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(),cerr.tie(0);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int _ = 1; _ < n; ++_) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  const int r = 0;
  vector<bool> u(n);
  vector<int> depth(n);
  deque<int> bfs = {r};
  while (!bfs.empty()) {
    auto v = bfs.front();
    u[v] = true;
    bfs.pop_front();
    for (auto w : g[v]) {
      if (!u[w]) {
        depth[w] = depth[v] + 1;
        bfs.push_back(w);
      }
    }
  }
  while (q--) {
    int c, d;
    cin >> c >> d;
    --c, --d;
    cout << ((depth[c] + depth[d]) & 1 ? "Road" : "Town") << "\n";
  }
  return 0;
}
