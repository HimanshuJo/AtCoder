#include <bits/stdc++.h>
using namespace std;

int64_t solve(vector<pair<int64_t, int64_t>> wv, vector<int64_t> xx) {
  int64_t n = wv.size(), m = xx.size(), i = 0, j = 0, a = 0;
  multiset<int64_t> v;
  while (j < m) {
    if (i < n && wv[i].first <= xx[j]) {
      v.insert(wv[i].second);
      ++i;
    } else {
      ++j;
      if (!v.empty()) {
        auto it = prev(v.end());
        a += *it;
        v.erase(it);
      }
    }
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int64_t n, m, q;
  cin >> n >> m >> q;
  vector<pair<int64_t, int64_t>> wv(n);
  for (auto& [wi, vi] : wv) {
    cin >> wi >> vi;
  }
  sort(wv.begin(), wv.end());
  vector<int64_t> x(m);
  for (auto& xj : x) {
    cin >> xj;
  }
  while (q--) {
    int64_t l, r;
    cin >> l >> r;
    --l, --r;
    vector<int64_t> xx;
    for (int64_t i = 0; i < l; ++i) {
      xx.push_back(x[i]);
    }
    for (int64_t i = r + 1; i < m; ++i) {
      xx.push_back(x[i]);
    }
    sort(xx.begin(), xx.end());
    cout << solve(wv, xx) << "\n";
  }

  return 0;
}
