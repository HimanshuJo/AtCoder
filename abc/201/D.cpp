#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  for (auto& ai : a) {
    cin >> ai;
  }
  auto score = [&] (int i, int j) -> int {
    return (a[i][j] == '+') ? 1 : -1;
  };
  vector<vector<int>> max_min(h, vector<int>(w));
  // (i + j) & 1 - Aoki
  for (int i = h - 1; i >= 0; --i) {
    for (int j = w - 1; j >= 0; --j) {
      if ((i + j) & 1) {  // Aoki
        if (i + 1 < h || j + 1 < w) {
          max_min[i][j] = h * w;
        }
        if (i + 1 < h) {
          max_min[i][j] = min(max_min[i][j], max_min[i + 1][j] - score(i + 1, j));
        }
        if (j + 1 < w) {
          max_min[i][j] = min(max_min[i][j], max_min[i][j + 1] - score(i, j + 1));
        }
      } else {  // Takahashi
        if (i + 1 < h || j + 1 < w) {
          max_min[i][j] = - h * w;
        }
        if (i + 1 < h) {
          max_min[i][j] = max(max_min[i][j], max_min[i + 1][j] + score(i + 1, j));  
        }
        if (j + 1 < w) {
          max_min[i][j] = max(max_min[i][j], max_min[i][j + 1] + score(i, j + 1));
        }
      }
    }
  }
  if (max_min[0][0] > 0) {
    cout << "Takahashi\n";
  } else if (max_min[0][0] < 0) {
    cout << "Aoki\n";
  } else {
    cout << "Draw\n";
  }
  return 0;
}
