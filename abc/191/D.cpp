#include <bits/stdc++.h>
using namespace std;

inline bool inside(int64_t cx, int64_t cy, int64_t r, int64_t x, int64_t y) {
  return (cx - x) * (cx - x) + (cy - y) * (cy - y) <= r * r;
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  long double _cx, _cy, _r;
  cin >> _cx >> _cy >> _r;
  const int64_t k = 10'000;
  int64_t cx = round(_cx * k), cy = round(_cy * k), r = round(_r * k);
  cerr << cx << " " << cy << " " << r << "\n";

  int64_t a = 0;
  for (int64_t x = (cx - r) / k * k; x <= (cx + r) / k * k; x += k) {
    if (r * r >= (cx - x) * (cx - x)) {
      int64_t h = cy + sqrtl(r * r - (cx - x) * (cx - x));
      h = h / k * k;
      if (inside(cx, cy, r, x, h + k)) {
        h += k;
      } else if (!inside(cx, cy, r, x, h)) {
        h -= k;
      }

      int64_t l = cy - sqrtl(r * r - (cx - x) * (cx - x));
      l = (l + k - 1) / k * k;
      if (inside(cx, cy, r, x, l - k)) {
        l -= k;
      } else if (!inside(cx, cy, r, x, l)) {
        l += k;
      }

      if (h >= l) {
        a += (h - l) / k + 1;
      }
    }
  }

  cout << a << "\n";

  return 0;
}
