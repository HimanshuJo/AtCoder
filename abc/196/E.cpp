#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  vector<pair<int64_t, int>> at(n);
  for (auto& [a, t] : at) {
    cin >> a >> t;
  }
  int64_t low = numeric_limits<int64_t>::min() / 4,
          high = numeric_limits<int64_t>::max() / 4,
          delta = 0;
  for (auto [a, t] : at) {
    if (t == 1) {
      low += a;
      high += a;
      delta += a;
    } else if (t == 2) {
      low = max(low, a);
      high = max(high, a);
    } else {  // t == 3
      low = min(low, a);
      high = min(high, a);
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int x;
    cin >> x;
    cout << max(low, min(high, x + delta)) << "\n";
  }
  return 0;
}