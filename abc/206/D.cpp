#include <bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
  public:
    explicit DisjointSetUnion(int size) : size_(size) {
      rank_.resize(size_);
      parent_.resize(size_);
      std::iota(parent_.begin(), parent_.end(), 0);
    }

    int Size() const {
      return size_;
    }

    int Find(int vertex) const {
      return (vertex == parent_[vertex]) ? \
        vertex : (parent_[vertex] = Find(parent_[vertex]));
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

  private:
    int size_;
    mutable std::vector<int> parent_;
    std::vector<int> rank_;
};

const int kMaxAi = 200'200;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  DisjointSetUnion disjoint_set_union(kMaxAi);
  for (int i = 0, j = n - 1; i < j; ++i, --j) {
    disjoint_set_union.Union(a[i], a[j]);
  }
  cout << kMaxAi - disjoint_set_union.Size() << "\n";
  return 0;
}
