#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> t(n);
  for (auto& ti : t) {
    cin >> ti;
  }
  const int k = 100'000;
  bitset<k + 1> dp = 1;
  for (auto ti : t) {
    dp |= dp << ti;
  }
  auto s = accumulate(t.begin(), t.end(), 0);
  for (int i = (s + 1) / 2; i <= s; ++i) {
    if (dp[i]) {
      cout << i << "\n";
      return 0;
    }
  }

  assert(false);
  return 0;
}