#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
  }
  // naive O(n^2)
  int best = 2e5;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i == j) {
        best = min(best, a[i] + b[j]);
      } else {
        best = min(best, max(a[i], b[j]));
      }
    }
  }
  cout << best << "\n";
  return 0;
}
