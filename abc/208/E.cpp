#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  string n;
  int64_t k;
  cin >> n >> k;
  unordered_map<int64_t, int64_t> cnt;
  int m = n.length();
  int64_t p = 1;
  for (int i = 0; i < m; ++i) {
    unordered_map<int64_t, int64_t> ncnt;
    // common prefix with product p
    for (int d = i ? 0 : 1; d < n[i] - '0'; ++d) {
      ++ncnt[p * d];
    }
    if (i) {  // has fewer digits than n
      for (int d = 1; d <= 9; ++d) {
        ++ncnt[d];
      }
    }
    p *= n[i] - '0';
    for (auto [key, v] : cnt) {  // already less than n
      for (int d = 0; d <= 9; ++d) {
        ncnt[key * d] += v;
      }
    }
    swap(cnt, ncnt);
    // cerr << "i = " << i << "\n";
    // for (auto [key, v] : cnt) {
    //   cerr << key << " -> " << v << "\n";
    // }
    // cerr << "\n";
  }
  ++cnt[p];
  int64_t ans = 0;
  for (auto [key, v] : cnt) {
    if (key <= k) {
      ans += v;
    }
  }
  cout << ans;
  return 0;
}