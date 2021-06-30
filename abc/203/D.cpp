#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(n, vector<int>(n));
  for (auto& ai : a) {
    for (auto& aij : ai) {
      cin >> aij;
    }
  }
  vector<vector<int>> b(n + 1, vector<int>(n + 1));
  auto can = [&] (int mi) -> bool {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        b[i + 1][j + 1] = b[i + 1][j] + b[i][j + 1] - b[i][j] + int(a[i][j] <= mi);
      }
    }
    for (int i = 0; i + k <= n; ++i) {
      for (int j = 0; j + k <= n; ++j) {
        if (b[i + k][j + k] - b[i + k][j] - b[i][j + k] + b[i][j] >= (k * k + 1) / 2) {
          return true;
        }
      }
    }
    return false;
  };
  int lo = -1, hi = 1e9;
  while (lo + 1 < hi) {
    int mi = (lo + hi) >> 1;
    if (can(mi)) {
      hi = mi;
    } else {
      lo = mi;
    }
  }
  cout << hi << "\n";
  return 0;
}
