#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int64_t r, x, y;
  cin >> r >> x >> y;
  if (x * x + y * y < r * r) {
    cout << 2 << "\n";
  } else {
    int64_t k = sqrtl((x * x + y * y) / (r * r));
    if (k * k * r * r == x * x + y * y) {
      cout << k << "\n";
    } else {
      cout << k + 1 << "\n";
    }
  }
  return 0;
}
