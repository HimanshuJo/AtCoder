#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;
struct FenwickTree {
  int size_;
  vector<int64_t> tree_;
  FenwickTree(int64_t size) : size_(size) {
    tree_.resize(size);
  }
  void Initialize(const vector<int64_t>& array) {
    for (int64_t index = 0; index < size_; ++index) {
      Increment(index, index, array[index]);
    }
  }
  int64_t Query(int index) const {
    return Sum(index);
  }
  void Increment(int left, int right, int64_t delta) {
    Increment(left, delta);
    Increment(right + 1, -delta);
  }
  int64_t Sum(int right) const {
    int64_t sum = 0;
    for (; right >= 0; right = (right & (right + 1)) - 1) {
      sum += tree_[right];
    }
    return sum;
  }
  void Increment(int index, int64_t delta) {
    for (; index < size_; index = (index | (index + 1))) {
      tree_[index] += delta;
    }
  }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(),cout.tie(0),cerr.tie(0);
  int qc;
  cin >> qc;
  set<int> as = {-2'000'000'000, 2'000'000'000};
  vector<tuple<int, int, int>> qs(qc);
  for (auto& [t, a, b] : qs) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b;
      as.insert(a);
    }
  }
  unordered_map<int, int> mp;
  for (auto a : as) {
    mp[a] = mp.size();
  }
  int n = mp.size();
  ordered_set<pair<int, int>> os;
  vector fts(2, FenwickTree(n));
  for (auto& [t, a, b] : qs) {
    if (t == 1) {
      os.insert(make_pair(a, os.size()));
      fts[0].Increment(0, mp[a], -1);
      fts[0].Increment(mp[a], n, +1);
      fts[1].Increment(0, n, b);
      fts[1].Increment(0, mp[a], a);
      fts[1].Increment(mp[a], n, -a);
    } else {
      int ma = os.find_by_order((os.size() - 1) / 2)->first;
      cout << ma << " " << fts[0].Query(mp[ma]) * ma + fts[1].Query(mp[ma]) << "\n";
    }
  }
  return 0;
}
