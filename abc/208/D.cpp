#include <bits/stdc++.h>
using namespace std;
const int inf = numeric_limits<int>::max();
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> g(n);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    g[a].emplace_back(b, c);
  }
  vector d(n, vector(n, inf));
  for (int a = 0; a < n; ++a) {
    d[a][a] = 0;
  }
  for (int a = 0; a < n; ++a) {
    for (auto [b, c] : g[a]) {
      d[a][b] = min(d[a][b], c);
    }
  }
  int64_t ss = 0;
  for (int k = 0; k < n; ++k) {
    for (int s = 0; s < n; ++s) {
      for (int f = 0; f < n; ++f) {
        if (d[s][k] != inf && d[k][f] != inf) {
          d[s][f] = min(d[s][k] + d[k][f], d[s][f]);
        }
      }
    }
    for (int s = 0; s < n; ++s) {
      for (int f = 0; f < n; ++f) {
        if (d[s][f] != inf) {
          ss += d[s][f];
        }
      }
    }
  }
  cout << ss << "\n";
  return 0;
}