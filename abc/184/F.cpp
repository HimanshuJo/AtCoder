#include <bits/stdc++.h>
using namespace std;

vector<int64_t> subset_sums(const vector<int>& a) {
  const int k = a.size();
  vector<int64_t> ss(1 << k);
  for (int m = 0; m < (1 << k); ++m) {
    int64_t s = 0;
    for (int i = 0; i < k; ++i) {
      if (m & (1 << i)) {
        s += a[i];
      }
    }
    ss[m] = s;
  }
  return ss;
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, t;
  cin >> n >> t;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }

  if (n == 1) {
    cout << (a[0] <= t ? a[0] : 0) << "\n";
    return 0;
  }

  int half = n >> 1;
  auto mi = next(a.begin(), half);
  vector<int> head(a.begin(), mi), tail(mi, a.end());

  auto b = subset_sums(head), c = subset_sums(tail);
  sort(b.begin(), b.end());

  int64_t mx = 0;
  for (auto ci : c) {
    auto j = distance(b.begin(), lower_bound(b.begin(), b.end(), t - ci + 1)) - 1;
    if (0 <= j) {
      mx = max(mx, ci + b[j]);
    }
  }
  cout << mx << "\n";

  return 0;
}
