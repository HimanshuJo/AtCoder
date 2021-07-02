#include <bits/stdc++.h>
using namespace std;
struct DSU {
  DSU(int size, vector<int> c) {
    cnt_.resize(size);
    for (int i = 0; i < size; ++i) {
      ++cnt_[i][c[i]];
    }
    parent_.resize(size);
    std::iota(parent_.begin(), parent_.end(), 0);
  }
  int Find(int vertex) {
    return (vertex == parent_[vertex]) ? vertex : (parent_[vertex] = Find(parent_[vertex]));
  }
  void Union(int first, int second) {
    first = Find(first), second = Find(second);
    if (first != second) {
      if (cnt_[first].size() < cnt_[second].size()) {
        std::swap(first, second);
      }
      parent_[second] = first;
      for (auto [k, v] : cnt_[second]) {
        cnt_[first][k] += v;
      }
    }
  }
  std::vector<int> parent_;
  vector<unordered_map<int, int>> cnt_;
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  for (auto& ci : c) {
    cin >> ci;
  }
  DSU dsu(n, c);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      --a, --b;
      dsu.Union(a, b);
    } else {  // t == 2
      int x, y;
      cin >> x >> y;
      --x;
      cout << dsu.cnt_[dsu.Find(x)][y] << "\n";
    }
  }
  return 0;
}