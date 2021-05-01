#include <bits/stdc++.h>
using namespace std;
class DSU {
  public:
    explicit DSU(int size) : size_(size) {
      rank_.resize(size);
      parent_.resize(size);
      std::iota(parent_.begin(), parent_.end(), 0);
    }
    int Find(int vertex) const {
      return (vertex == parent_[vertex]) ? vertex : (parent_[vertex] = Find(parent_[vertex]));
    }
    void Union(int first, int second) {
      first = Find(first), second = Find(second);
      if (first != second) {
        --size_;
        if (rank_[first] < rank_[second]) {
          std::swap(first, second);
        }
        parent_[second] = first;
        if (rank_[first] == rank_[second]){
          ++rank_[first];
        }
      }
    }
    int Size() const {
      return size_;
    }
  private:
    int size_;
    mutable std::vector<int> parent_;
    std::vector<int> rank_;
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  int k = log2(n) + 0.5;
  vector<int> a(m);
  for (auto& ai : a) {
    cin >> ai;
  }
  DSU dsu(n);
  vector<pair<int, int>> edges;
  vector<unordered_set<int>> used(k);
  for (int _ = 0; _ < 10; ++ _) {
    int mask = 0;
    for (int i = 0, j = 0; i < n; ++i) {
      if (j < m && i == a[j]) {
        ++j;
      } else {
        for (int l = 0; l < k; ++l) {
          if ((i & (1 << l)) && !(mask & (1 << l)) && !used[l].count(i)) {
            mask |= 1 << l;
            used[l].insert(i);
            for (int ii = 0; ii < n; ++ii) {
              if (dsu.Find(ii) != dsu.Find(ii ^ i)) {
                dsu.Union(ii, ii ^ i);
                edges.emplace_back(ii, ii ^ i);
              }
            }
          }
        }
      }
    }
  }
  if (dsu.Size() == 1) {
    for (auto [u, v] : edges) {
      cout << u << " " << v << "\n";
    }
    cout << "\n";
  } else {
    cout << -1 << "\n";
  }
  return 0;
}
