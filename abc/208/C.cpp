#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int64_t n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  auto [q, r] = div(k, n);
  vector<pair<int, int>> ia;
  ia.reserve(n);
  for (int i = 0; i < n; ++i) {
    ia.emplace_back(a[i], i);
  }
  sort(ia.begin(), ia.end());
  vector<int64_t> b(n, q);
  for (int i = 0; i < r; ++i) {
    ++b[ia[i].second];
  }
  for (auto bi : b) {
    cout << bi << "\n";
  }
  return 0;
}