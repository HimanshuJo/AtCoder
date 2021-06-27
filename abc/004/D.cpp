#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int r, g, b;
  cin >> r >> g >> b;
  int best = 1e9;
  auto cost = [&] (int l, int c, int r) -> int {
    int a = 0;
    for (int i = l; i <= r; ++i) {
      a += abs(i - c);
    }
    return a;
  };
  for (int gl = -400, gr = -400 + g - 1; gr <= 400; ++gl, ++gr) {
    int rr = min(-100 + (r - 1) / 2, gl - 1);
    int rl = rr - r + 1;
    int bl = max(100 - (b - 1) / 2, gr + 1);
    int br = bl + b - 1;
    best = min(best, cost(rl, -100, rr) + cost(gl, 0, gr) + cost(bl, 100, br));
  }
  cout << best;
  return 0;
}
