#include <bits/stdc++.h>
using namespace std;
auto sieve(int n) {
  vector<int> pd(n);
  iota(pd.begin(), pd.end(), 0);
  for (int d = 2; d * d < n; ++d) {
    if (pd[d] == d) {
      for (int m = d * d; m < n; m += d) {
        pd[m] = d;
      }
    }
  }
  return pd;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  auto pd = sieve(n + 1);
  int64_t d = 0;
  auto cd = [&] (int x) -> int {
    unordered_map<int, int> f;
    while (x > 1) {
      ++f[pd[x]];
      x /= pd[x];
    }
    int dc = 1;
    for (auto [k, v] : f) {
      dc *= v + 1;
    }
    return dc;
  };
  for (int c = 1; c < n; ++c) {
    d += cd(n - c);
  }
  cout << d << "\n";
  return 0;
}