#include <bits/stdc++.h>
using namespace std;
const int mod = 1'000'000'007;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(),cerr.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  for (auto& ci : c) {
    cin >> ci;
  }
  sort(c.begin(), c.end());
  int64_t p = 1;
  for (int i = 0; i < n; ++i) {
    p *= c[i] - i;
    p %= mod;
  }
  cout << p << "\n";
  return 0;
}