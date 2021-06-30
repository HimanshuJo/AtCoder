#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int h, w, x, y;
  cin >> h >> w >> x >> y;
  --x, --y;
  vector<string> s(h);
  for (auto& si : s) {
    cin >> si;
  }

  int c = 0;
  vector<pair<int, int>> d = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
  for (auto [dx, dy] : d) {
    for (int i = x, j = y;
         0 <= i && i < h &&
         0 <= j && j < w &&
         s[i][j] != '#';
         i += dx, j += dy) {
      ++c;
    }
  }

  cout << c - 3 << "\n";

  return 0;
}
