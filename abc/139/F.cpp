#include <bits/stdc++.h>
using namespace std;
template <typename ftype>
struct point2d {
  ftype x, y;
  point2d() {}
  point2d(ftype x, ftype y): x(x), y(y) {}
  point2d& operator+=(const point2d& t) {
    x += t.x;
    y += t.y;
    return *this;
  }
  point2d& operator-=(const point2d& t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point2d operator+(const point2d& t) const {
    return point2d(*this) += t;
  }
  point2d operator-(const point2d& t) const {
    return point2d(*this) -= t;
  }
  bool operator!=(const point2d& t) const {
    return x != t.x || y != t.y;
  }
};
template <typename ftype>
ftype dot(point2d<ftype> a, point2d<ftype> b) {
  return a.x * b.x + a.y * b.y;
}
template <typename ftype>
ftype norm(point2d<ftype> a) {
  return dot(a, a);
}
template <typename ftype>
ftype cross(point2d<ftype> a, point2d<ftype> b) {
  return a.x * b.y - a.y * b.x;
}
template <typename ftype>
ftype signed_area_parallelogram(point2d<ftype> p1, point2d<ftype> p2, point2d<ftype> p3) {
  return cross(p2 - p1, p3 - p2);
}
template <typename ftype>
bool counter_clockwise(point2d<ftype> p1, point2d<ftype> p2, point2d<ftype> p3) {
  return signed_area_parallelogram(p1, p2, p3) > 0;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  point2d<int64_t> o(0, 0);
  vector<point2d<int64_t>> ps;
  for (int i = 0; i < n; ++i) {
    point2d<int64_t> p;
    cin >> p.x >> p.y;
    if (p != o) {
      ps.push_back(p);
    }
  }
  n = ps.size();
  int64_t mx = 0;
  // 90 degrees
  for (int i = 0; i < n; ++i) {
    point2d<int64_t> l(0, 0), s(0, 0), r(0, 0);
    for (int j = 0; j < n; ++j) {
      if (dot(ps[i], ps[j]) > 0) {
        s += ps[j];
      } else if (!dot(ps[i], ps[j])) {
        if (counter_clockwise(ps[i], o, ps[j])) {
          l += ps[j];
        } else {
          r += ps[j];
        }
      }
    }
    mx = max({mx, norm(s + l), norm(s + r)});
  }
  // 180 degrees
  for (int i = 0; i < n; ++i) {
    point2d<int64_t> s(0, 0);
    for (int j = 0; j < n; ++j) {
      if (counter_clockwise(ps[i], o, ps[j])) {
        s += ps[j];
      } else if (!cross(ps[i], ps[j]) && dot(ps[i], ps[j]) > 0) {
        s += ps[j];
      }
    }
    mx = max(mx, norm(s));
  }
  cout << fixed << setprecision(12) << sqrtl(static_cast<long double>(mx)) << "\n"; 
  return 0;
}
