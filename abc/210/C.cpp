#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  for (auto& ci : c) {
    cin >> ci;
  }
  int mx = 0;
  unordered_map<int, int> f;
  for (int i = 0; i < n; ++i) {
    ++f[c[i]];
    if (i >= k) {
      --f[c[i - k]];
      if (!f[c[i - k]]) {
        f.erase(c[i - k]);
      }
    }
    mx = max<int>(mx, f.size());
  }
  cout << mx << "\n";
  return 0;
}