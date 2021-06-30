#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> xys(m);
  for (auto& xy : xys) {
    cin >> xy.second >> xy.first;
  }
  sort(xys.begin(), xys.end(), [] (const auto& first, const auto& second) -> bool {
    return make_pair(first.second, first.first) < make_pair(second.second, second.first);
  });
  unordered_map<int, bool> can;
  int cy = 0;
  vector<pair<int, bool>> upd = {{n, true}};
  for (auto [x, y] : xys) {
    if (y != cy) {
      cy = y;
      for (auto [xx, b] : upd) {
        can[xx] = b;
      }
      upd.clear();
    }
    if ((x - 1 >= 0 && can[x - 1]) || (x + 1 <= (n << 1) && can[x + 1])) {
      upd.emplace_back(x, true);
    } else {
      upd.emplace_back(x, false);
    }
  }
  for (auto [x, b] : upd) {
    can[x] = b;
  }
  int cnt = 0;
  for (auto [k, v] : can) {
    if (v) {
      ++cnt;
    }
  }
  cout << cnt << "\n";
  return 0;
}
