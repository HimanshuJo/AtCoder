#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  int c = 0;
  function<void(int, int, int, int)> dfs = [&] (int i, int mask, int a, int b) -> void {
    if (i == h * w) {
      ++c;
    } else if (mask & (1 << i)) {
      dfs(i + 1, mask, a, b);
    } else {
      if (b) {
        dfs(i + 1, mask | (1 << i), a, b - 1);
      }
      if (a) {
        if (i % w != w - 1 && !(mask & (1 << i + 1))) {
          dfs(i + 1, mask | (1 << i) | (1 << (i + 1)), a - 1, b);
        }
        if (i + w < h * w) {
          dfs(i + 1, mask | (1 << i) | (1 << (i + w)), a - 1, b);
        }
      }
    }
  };
  dfs(0, 0, a, b);
  cout << c << "\n";
  return 0;
}