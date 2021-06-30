#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }

  int mn = numeric_limits<int>::max();

  for (int mask = 0; mask < (1 << (n - 1)); ++mask) {
    int x = 0, c = a[0];
    for (int i = 1; i < n; ++i) {
      if (mask & (1 << (i - 1))) {
        c |= a[i];
      } else {
        x ^= c;
        c = a[i];
      }
    }
    x ^= c;
    mn = min(mn, x);
  }

  cout << mn << "\n";

  return 0;
}
