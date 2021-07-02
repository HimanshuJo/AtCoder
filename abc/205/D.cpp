#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int64_t> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  while (q--) {
    int64_t k;
    cin >> k;
    int64_t lo = 0, hi = n + 1;
    while (lo + 1 < hi) {
      int64_t mi = (lo + hi) >> 1;
      if (a[mi] - mi < k) {
        lo = mi;
      } else {
        hi = mi;
      }
    }
    cout << k + lo << "\n";
  }
  return 0;
}