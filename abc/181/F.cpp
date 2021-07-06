#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
// https://cp-algorithms.com/geometry/basic-geometry.html
using ftype = long double;
struct point2d {
  ftype x, y;
  point2d() {}
  point2d(ftype x, ftype y): x(x), y(y) {}
  point2d& operator-=(const point2d &t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point2d operator-(const point2d &t) const {
    return point2d(*this) -= t;
  }
};
ftype dot(point2d a, point2d b) {
  return a.x * b.x + a.y * b.y;
}
ftype norm(point2d a) {
  return dot(a, a);
}
int main() {
  ios::sync_with_stdio(0),cin.tie(),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  vector<point2d> ps(n);
  for (auto& p : ps) {
    cin >> p.x >> p.y;
  }
  auto can = [&] (long double r) -> bool {
    long double d = 2 * r;
    dsu c(n + 2);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (norm(ps[i] - ps[j]) < d * d) {
          c.merge(i, j);
        }
      }
    }
    const int UP = n, DOWN = n + 1; 
    for (int i = 0; i < n; ++i) {
      if (ps[i].y + d > 100) {
        c.merge(i, UP);
      }
      if (ps[i].y - d < -100) {
        c.merge(i, DOWN);
      }
    }
    return !c.same(UP, DOWN);
  };
  long double lo = 0, hi = 101, eps = 1e-6;
  while (lo + eps < hi) {
    long double mi = (lo + hi) / 2;
    if (can(mi)) {
      lo = mi;
    } else {
      hi = mi;
    }
  }
  cout << fixed << setprecision(10) << lo << "\n";
  return 0;
}
