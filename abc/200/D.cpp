#include <bits/stdc++.h>
using namespace std;
#ifdef _MSC_VER
#  include <intrin.h>
#  define __builtin_popcount __popcnt
#endif
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  n = min(n, 8);
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  vector<int> f(200, -1);
  for (int mask = 1; mask < (1 << n); ++mask) {
    int64_t sum = 0;
    for (int bit = 0; bit < n; ++bit) {
      if (mask & (1 << bit)) {
        sum += a[bit];
      }
    }
    sum %= 200;
    if (f[sum] != -1) {
      auto print_mask = [&] (int mask) -> void {
        cout << __builtin_popcount(mask) << " ";
        for (int bit = 0; bit < n; ++bit) {
          if (mask & (1 << bit)) {
            cout << bit + 1 << " ";
          }
        }
        cout << "\n";
      };
      cout << "Yes\n";
      print_mask(f[sum]);
      print_mask(mask);
      return 0;
    } else {
      f[sum] = mask;
    }
  }
  cout << "No\n";
  return 0;
}