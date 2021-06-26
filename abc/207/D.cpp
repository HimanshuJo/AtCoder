#include <bits/stdc++.h>
using namespace std;

// https://cp-algorithms.com/geometry/basic-geometry.html
struct point2d {
  int x, y;
  point2d() {}
  point2d(int x, int y): x(x), y(y) {}
  point2d& operator+=(const point2d &t) {
    x += t.x;
    y += t.y;
    return *this;
  }
  point2d& operator-=(const point2d &t) {
    x -= t.x;
    y -= t.y;
    return *this;
  }
  point2d& operator*=(int t) {
    x *= t;
    y *= t;
    return *this;
  }
  point2d& operator/=(int t) {
    x /= t;
    y /= t;
    return *this;
  }
  point2d operator+(const point2d &t) const {
    return point2d(*this) += t;
  }
  point2d operator-(const point2d &t) const {
    return point2d(*this) -= t;
  }
  point2d operator*(int t) const {
    return point2d(*this) *= t;
  }
  point2d operator/(int t) const {
    return point2d(*this) /= t;
  }
};
point2d operator*(int a, point2d b) {
    return b * a;
}

int dot(point2d a, point2d b) {
  return a.x * b.x + a.y * b.y;
}

int norm(point2d a) {
  return dot(a, a);
}
double abs(point2d a) {
  return sqrt(norm(a));
}
double proj(point2d a, point2d b) {
  return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) {
  return acos(dot(a, b) / abs(a) / abs(b));
}

int cross(point2d a, point2d b) {
  return a.x * b.y - a.y * b.x;
}

// https://cp-algorithms.com/geometry/oriented-triangle-area.html
int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
  return cross(p2 - p1, p3 - p2);
}
double triangle_area(point2d p1, point2d p2, point2d p3) {
  return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
}
bool clockwise(point2d p1, point2d p2, point2d p3) {
  return signed_area_parallelogram(p1, p2, p3) < 0;
}
bool counter_clockwise(point2d p1, point2d p2, point2d p3) {
  return signed_area_parallelogram(p1, p2, p3) > 0;
}

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;

  if (n == 1) {
    cout << "Yes\n";
    return 0;
  }

  vector<point2d> s(n), t(n);
  for (auto& si : s) {
    cin >> si.x >> si.y;
  }
  for (auto& ti : t) {
    cin >> ti.x >> ti.y;
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && norm(s[1] - s[0]) == norm(t[j] - t[i])) {
        // s[0] -> t[i]
        // s[1] -> t[j]
        map<tuple<int, int, int>, int> mp;
        for (int k = 2; k < n; ++k) {
          ++mp[{norm(s[k] - s[0]), norm(s[k] - s[1]), clockwise(s[0], s[k], s[1])}];
        }
        for (int l = 0; l < n; ++l) {
          if (i != l && j != l) {
            --mp[{norm(t[l] - t[i]), norm(t[l] - t[j]), clockwise(t[i], t[l], t[j])}];
          }
        }
        bool all = true;
        for (auto [k, v] : mp) {
          if (v) {
            all = false;
          }
        }
        if (all) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }

  cout << "No\n";
  return 0;
}