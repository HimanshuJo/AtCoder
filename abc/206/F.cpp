#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

const string kFirst = "Alice", kSecond = "Bob";

using Interval = pair<int, int>;

void solve() {
  int n;
  cin >> n;
  vector<Interval> LR(n);
  for (auto& [l, r] : LR) {
    cin >> l >> r;
  }
  const int kMaxN = 111;
  auto mex = [&] (set<int> g) -> int {
    for (int i = 0; i < kMaxN; ++i) {
      if (!g.count(i)) {
        return i;
      }
    }
    return kMaxN;
  };
  vector<vector<int>> cache(kMaxN + 1, vector<int>(kMaxN + 1, -1));
  cache[kMaxN][0] = 0;
  function<int(int, int)> grundy = [&] (int ll, int rr) -> int {
    if (cache[ll][rr] == -1) {
      set<int> g;
      for (int i = 0; i < n; ++i) {
        if (ll <= LR[i].first && LR[i].second <= rr) {
          // https://cp-algorithms.com/game_theory/sprague-grundy-nim.html#toc-tgt-7
          // sum of independent games => xor-sum
          g.insert(grundy(ll, LR[i].first) ^ grundy(LR[i].second, rr));
        }
      }
      // https://cp-algorithms.com/game_theory/sprague-grundy-nim.html#toc-tgt-6
      cache[ll][rr] = mex(g);
    }
    return cache[ll][rr];
  };
  cout << (grundy(0, kMaxN) ? kFirst : kSecond) << "\n";
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int t; cin >> t; while (t--) solve();
  return 0;
}
