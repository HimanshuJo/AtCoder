#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  vector<int> b(m);
  for (auto& bj : b) {
    cin >> bj;
  }

  vector<pair<int, int>> c;
  for (auto ai : a) {
    c.emplace_back(ai, 0);
  }
  for (auto bj : b) {
    c.emplace_back(bj, 1);
  }
  sort(c.begin(), c.end());

  int mn = numeric_limits<int>::max();
  for (int i = 1; i < n + m; ++i) {
    if (c[i - 1].second != c[i].second) {
      mn = min(mn, c[i].first - c[i - 1].first);
    }
  }
  cout << mn << "\n";

  return 0;
}