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

  pair<int, int> s, g;
  vector<vector<pair<int, int>>> tp(26);
  for (int r = 0; r < h; ++r) {
    for (int c = 0; c < w; ++c) {
      if (a[r][c] == 'S') {
        s = {r, c};
      } else if (a[r][c] == 'G') {
        g = {r, c};
      } else if (a[r][c] == '.') {
        // pass?
      } else if (a[r][c] == '#') {
        // pass?
      } else {  // a-z
        tp[a[r][c] - 'a'].emplace_back(r, c);
      }
    }
  }

  auto nei = [&] (int r, int c) -> vector<pair<int, int>> {
    return {{r - 1, c}, {r, c - 1}, {r, c + 1}, {r + 1, c}};
  };

  deque<pair<int, int>> bfs = {s};
  vector<bool> u(26);
  const int inf = numeric_limits<int>::max();
  vector<vector<int>> d(h, vector<int>(w, inf));
  d[s.first][s.second] = 0;

  while (!bfs.empty()) {
    auto [r, c] = bfs.front();
    bfs.pop_front();

    // adjacent
    for (auto [nr, nc] : nei(r, c)) {
      if (0 <= nr && nr < h && 0 <= nc && nc < w &&
          a[nr][nc] != '#' && d[nr][nc] == inf) {
        d[nr][nc] = d[r][c] + 1;
        bfs.emplace_back(nr, nc);
      }
    }

    // teleport
    if ('a' <= a[r][c] && a[r][c] <= 'z' && !u[a[r][c] - 'a']) {
      u[a[r][c] - 'a'] = true;
      for (auto [nr, nc] : tp[a[r][c] - 'a']) {
        if (d[nr][nc] == inf) {
          d[nr][nc] = d[r][c] + 1;
          bfs.emplace_back(nr, nc);
        }
      }
    }
  }

  cout << (d[g.first][g.second] == inf ? -1 : d[g.first][g.second]) << "\n";

  return 0;
}
