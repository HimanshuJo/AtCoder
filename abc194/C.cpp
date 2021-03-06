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
  int64_t sosd = 0, sos = 0, s = 0;
  for (int64_t i = 0; i < n; ++i) {
    sosd += i * a[i] * a[i] - 2 * s * a[i] + sos;
    s += a[i];
    sos += a[i] * a[i];
  }
  cout << sosd << "\n";
  return 0;
}
