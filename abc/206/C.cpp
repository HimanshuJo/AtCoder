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
  unordered_map<int, int> f;
  int64_t c = 0;
  for (int j = 0; j < n; ++j) {
    c += j - f[a[j]];
    ++f[a[j]];
  }
  cout << c << "\n";
  return 0;
}
