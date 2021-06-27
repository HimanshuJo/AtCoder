#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t t, n;
  cin >> t >> n;
  // 1, 2, ..., mi -> f(1), f(2), ..., f(mi)
  // n = f(mi) - mi
  // f(mi) - 1
  int64_t lo = 0, hi = 1e14;
  while (lo + 1 < hi) {
    int64_t mi = lo + (hi - lo) / 2;
    int64_t skipped = ((100 + t) * mi) / 100 - mi;
    if (skipped >= n) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  cout << ((100 + t) * hi) / 100 - 1 << "\n";
  return 0;
}
