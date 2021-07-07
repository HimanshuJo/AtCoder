#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using matrix = vector<vector<mint>>;
matrix mul(matrix& a, matrix& b) {
  int n = a.size();
  matrix c(n, vector<mint>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}
matrix eye(int n) {
  matrix a(n, vector<mint>(n));
  for (int i = 0; i < n; ++i) {
    a[i][i] = 1;
  }
  return a;
}
matrix mpow(matrix& b, int k) {
  int n = b.size();
  auto c = eye(n);
  while (k) {
    if (k & 1) {
      c = mul(c, b);
    }
    b = mul(b, b);
    k >>= 1;
  }
  return c;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(),cout.tie(0),cerr.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  vector<vector<int>> g(n);
  for (int _ = 0; _ < m; ++_) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  mint den = mint(2 * m).inv();
  matrix b(n, vector<mint>(n));
  for (int i = 0; i < n; ++i) {
    for (int j : g[i]) {
      b[i][j] = den;
    }
    b[i][i] = 1 - g[i].size() * den;
  }
  auto c = mpow(b, k);
  for (int i = 0; i < n; ++i) {
    mint e = 0;
    for (int j = 0; j < n; ++j) {
      e += c[i][j] * a[j];
    }
    cout << e.val() << "\n";
  }
  return 0;
}
