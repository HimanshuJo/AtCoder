#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  for (auto& bi : b) {
    cin >> bi;
  }
  for (auto& ci : c) {
    cin >> ci;
  }
  unordered_map<int, int> fa;
  for (auto ai : a) {
    ++fa[ai];
  }
  unordered_map<int, int> fc;
  for (auto ci : c) {
    ++fc[ci];
  }
  unordered_map<int, int> fb;
  for (int i = 0; i < n; ++i) {
    fb[b[i]] += fc[i + 1];
  }
  int64_t ans = 0;
  for (auto [k, v] : fa) {
    ans += v * 1ll * fb[k];
  }
  cout << ans;
  return 0;
}
