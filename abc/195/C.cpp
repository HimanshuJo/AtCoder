#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int64_t n, c = 0;
  cin >> n;

  for (int64_t cc = 0, l = 1, r = 1'000; l <= n; l *= 1'000, r *= 1'000, ++cc) {
    c += cc * (min(r, n + 1) - l);
  }

  cout << c << "\n";

  return 0;
}
