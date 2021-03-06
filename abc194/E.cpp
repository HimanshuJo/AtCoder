#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  int min_mex = m;
  vector<int> f(m + 1);
  set<int> s;
  for (int i = 0; i <= m; ++i) {
    s.insert(i);
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] <= m) {
      if (!f[a[i]]) {
        s.erase(a[i]);
      }
      ++f[a[i]];
    }
    if (i >= m) {
      if (a[i - m] <= m) {
        --f[a[i - m]];
        if (!f[a[i - m]]) {
          s.insert(a[i - m]);
        }
      }
    }
    if (i >= m - 1) {
      min_mex = min(min_mex, *s.begin());
    }
  }
  cout << min_mex << "\n";
  return 0;
}
