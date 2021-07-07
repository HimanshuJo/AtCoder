#include <bits/stdc++.h>
#include <atcoder/convolution>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
int main() {
  ios::sync_with_stdio(0),cin.tie(),cout.tie(0),cerr.tie(0);
  string s, t;
  cin >> s >> t;
  auto enc = [&] (string& s) -> vector<vector<mint>> {
    int n = s.length();
    vector a(2, vector(n, mint(0)));
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        a[1][i] = 1;
      } else {
        a[0][i] = 1;
      }
    }
    return a;
  };
  reverse(t.begin(), t.end());
  auto a = enc(s), b = enc(t);
  auto c = convolution(a[0], b[1]);
  auto d = convolution(a[1], b[0]);
  int n = s.length(), m = t.length();
  unsigned int mn = m;
  for (int i = m - 1; i < n; ++i) {
    mn = min(mn, (c[i] + d[i]).val());
  }
  cout << mn << "\n";
  return 0;
}
