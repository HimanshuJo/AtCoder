#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), p(n), x(n);
  int best = 2e9;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> p[i] >> x[i];
    if (x[i] > a[i]) {
      best = min(best, p[i]);
    }
  }
  cout << ((best == 2e9) ? -1 : best) << "\n";
  return 0;
}
