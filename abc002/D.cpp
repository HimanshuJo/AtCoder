#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(n));
  while (m--) {
    int xi, yi;
    cin >> xi >> yi;
    --xi, --yi;
    g[xi][yi] = g[yi][xi] = 1;
  }
  int best = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    int size = 0;
    bool good = true;
    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        ++size;
        for (int j = 0; j < i; ++j) {
          if (mask & (1 << j)) {
            if (!g[i][j]) {
              good = false;
            }
          }
        }
      }
    }
    if (good) {
      best = max(best, size);
    }
  }
  cout << best << "\n";
  return 0;
}