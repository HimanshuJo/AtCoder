#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  int lo = 0, hi = n;
  while (lo + 1 < hi) {
    int mi = lo + (hi - lo) / 2;
    if ((mi + 1) * 1ll * mi >= 2 * n) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  cout << hi << "\n";
  return 0;
}
