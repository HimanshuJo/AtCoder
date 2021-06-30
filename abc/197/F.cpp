#include <bits/stdc++.h>
using namespace std;

const int inf = numeric_limits<int>::max();

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, m;
  cin >> n >> m;

  vector<unordered_set<int>> g(n);
  vector<vector<vector<int>>> gc(26, vector<vector<int>>(n));

  for (auto _ = 0; _ < m; ++_) {
    int a, b; char c;
    cin >> a >> b >> c;
    --a, --b, c -= 'a';
    g[a].insert(b);
    g[b].insert(a);
    gc[c][a].push_back(b);
    gc[c][b].push_back(a);
  }

  vector<vector<vector<pair<int, int>>>> gg(n,
    vector<vector<pair<int, int>>>(n));

  for (auto c = 0; c < 26; ++c) {
    for (int a = 0; a < n; ++a) {
      for (int b = 0; b < n; ++b) {
        for (auto u : gc[c][a]) {
          for (auto v : gc[c][b]) {
            gg[a][b].emplace_back(u, v);
          }
        }
      }
    }
  }

  vector<vector<int>> dd(n, vector<int>(n, inf));
  dd[0][n - 1] = 0;
  deque<pair<int, int>> bfs = {{0, n - 1}};
  int mn = inf;

  while (!bfs.empty()) {
    auto [u, v] = bfs.front();
    bfs.pop_front();

    if (u == v) {
      mn = min(mn, dd[u][v] << 1);
    }

    if (g[u].count(v)) {
      mn = min(mn, (dd[u][v] << 1) | 1);
    }

    for (auto [x, y] : gg[u][v]) {
      if (dd[x][y] == inf) {
        dd[x][y] = dd[u][v] + 1;
        bfs.emplace_back(x, y);
      }
    }
  }

  cout << (mn == inf ? -1 : mn) << "\n";

  return 0;
}
