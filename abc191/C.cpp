#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> g(h);
  for (auto& r : g)
    cin >> r;

  int a = 0;
  for (int i = 0; i + 1 < h; ++i) {
    for (int j = 1; j < w; ++j) {
      if ((g[i][j - 1] == g[i + 1][j - 1]) &&
          (g[i][j] != g[i + 1][j])) {
        ++a;
      }
    }
  }
  for (int j = 0; j + 1 < w; ++j) {
    for (int i = 1; i < h; ++i) {
      if ((g[i - 1][j] == g[i - 1][j + 1]) &&
          (g[i][j] != g[i][j + 1])) {
        ++a;
      }
    }
  }
  cout << a << "\n";

  return 0;
}
