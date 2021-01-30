#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t n, m;
  cin >> n >> m;
  vector<vector<int64_t>> g(n);
  while (m--) {
    int64_t ai, bi;
    cin >> ai >> bi;
    --ai, --bi;
    g[ai].push_back(bi);
    g[bi].push_back(ai);
  }
  int64_t k;
  cin >> k;
  vector<int64_t> c(k);
  for (auto& ci : c) {
    cin >> ci;
    --ci;
  }

  vector<vector<int64_t>> dist(k, vector<int64_t>(k, 0));
  for (int64_t i = 0; i < k; ++i) {
    vector<int64_t> d(n, n);
    d[c[i]] = 0;
    deque<int64_t> bfs = {c[i]};
    while (!bfs.empty()) {
      auto vertex = bfs.front();
      bfs.pop_front();
      for (auto adjacent : g[vertex]) {
        if (d[adjacent] > d[vertex] + 1) {
          bfs.push_back(adjacent);
          d[adjacent] = d[vertex] + 1;
        }
      }
    }
    for (int64_t j = 0; j < k; ++j) {
      dist[i][j] = d[c[j]];
    }
  }

  vector<vector<int64_t>> dp(k, vector<int64_t>(1 << k, k * n));
  for (int64_t first = 0; first < k; ++first) {
    dp[first][1 << first] = 0;
  }
  for (int64_t bitmask = 0; bitmask < (1 << k); ++bitmask) {
    for (int64_t last = 0; last < k; ++last) {
      if (bitmask & (1 << last)) {
        int64_t prev_mask = bitmask - (1 << last);
        for (int64_t prev_last = 0; prev_last < k; ++prev_last) {
          if (prev_mask & (1 << prev_last)) {
            if (dp[prev_last][prev_mask] != k * n && dist[prev_last][last] != n) {
              dp[last][bitmask] = min(dp[last][bitmask],
                dp[prev_last][prev_mask] + dist[prev_last][last]);
            }
          }
        }
      }
    }
  }

  int64_t ans = k * n;
  for (int64_t last = 0; last < k; ++last) {
    ans = min(ans, dp[last][(1 << k) - 1]);
  }
  if (ans == k * n) {
    cout << -1 << "\n";
  } else {
    cout << ans + 1 << "\n";
  }

  return 0;
}
