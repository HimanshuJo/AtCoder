#include <bits/stdc++.h>
using namespace std;
const int64_t inf64_t = numeric_limits<int64_t>::max(); 
struct Edge {
  int b, c, d;
  Edge(int b_, int c_, int d_) : b(b_), c(c_), d(d_) { }
};
inline int64_t time(int64_t t, int c, int d) {
  return c + d / (t + 1);
}
inline int64_t opt(int64_t t, int c, int d) {
  int64_t opt = round(sqrt(d)) - 1;
  return opt >= t ? time(opt, c, d) + opt - t : time(t, c, d);
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> g(n);
  while (m--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    --a, --b;
    g[a].emplace_back(b, c, d);
    g[b].emplace_back(a, c, d);
  }
  vector<int64_t> d(n, inf64_t);
  d[0] = 0;
  priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<>> pq;
  pq.emplace(0, 0);
  while (!pq.empty()) {
    auto [dv, v] = pq.top();
    pq.pop();
    if (dv == d[v]) {
      for (auto edge : g[v]) {
        auto dopt = dv + opt(dv, edge.c, edge.d);
        if (d[edge.b] > dopt) {
          d[edge.b] = dopt;
          pq.emplace(dopt, edge.b);
        }
      }
    }
  }
  cout << (d[n - 1] == inf64_t ? -1 : d[n - 1]) << "\n";
  return 0;
}