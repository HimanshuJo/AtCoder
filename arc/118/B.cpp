#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t k, n, m;
  cin >> k >> n >> m;
  vector<int64_t> a(k);
  for (auto& ai : a) {
    cin >> ai;
  }
  auto bounds = [&] (int64_t ai, int64_t e) -> pair<int64_t, int64_t> {
    return {(ai * m - e + n - 1) / n, (ai * m + e) / n};
  };
  auto possible = [&] (int64_t e) -> bool {
    int64_t l = 0, r = 0;
    for (int64_t i = 0; i < k; ++i) {
      auto [li, ri] = bounds(a[i], e);
      if (ri < li) {
        return false;
      }
      l += li;
      r += ri;
    }
    return l <= m && m <= r;
  };
  int64_t lo = -1, hi = n * m + 1;
  while (lo + 1 < hi) {
    auto mi = lo + (hi - lo) / 2;
    if (possible(mi)) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  int64_t l = 0, r = 0;
  for (int64_t i = 0; i < k; ++i) {
    auto [li, ri] = bounds(a[i], hi);
    l += li;
    r += ri;
  }
  int64_t diff = m - l;
  vector<int64_t> b(k);
  for (int64_t i = 0; i < k; ++i) {
    auto [li, ri] = bounds(a[i], hi);
    auto di = min(ri - li, diff);
    diff -= di;
    b[i] = li + di;
  }
  for (auto bi : b) {
    cout << bi << " ";
  }
  return 0;
}
