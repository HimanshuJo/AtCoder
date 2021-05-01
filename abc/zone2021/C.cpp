#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  const int k = 5;
  vector<array<int, k>> a(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }
  auto possible = [&] (int mi) -> bool {
    unordered_set<int> masks;
    for (int i = 0; i < n; ++i) {
      int mask = 0;
      for (int j = 0; j < k; ++j) {
        if (a[i][j] >= mi) {
          mask |= 1 << j;
        }
      }
      masks.insert(mask);
    }
    for (int first : masks) {
      for (int second : masks) {
        for (int third : masks) {
          if ((first | second | third) + 1 == (1 << k)) {
            return true;
          }
        }
      }
    }
    return false;
  };
  int lo = 1, hi = 1'000'000'001;
  while (lo + 1 < hi) {
    int mi = lo + (hi - lo) / 2;
    if (possible(mi)) {
      lo = mi;
    } else {
      hi = mi;
    }
  }
  cout << lo << "\n";
  return 0;
}
