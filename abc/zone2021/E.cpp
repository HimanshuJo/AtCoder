#include <bits/stdc++.h>
using namespace std;
struct Cell {
  int f, r, c, d;
  Cell (int f_, int r_, int c_, int d_) : f(f_), r(r_), c(c_), d(d_) { };
  inline bool operator<(const Cell& other) const { return d > other.d; }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int r, c;
  cin >> r >> c;
  vector<vector<int>> a(r, vector<int>(c - 1)), b(r - 1, vector<int>(c));
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j + 1 < c; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i + 1 < r; ++i) {
    for (int j = 0; j < c; ++j) {
      cin >> b[i][j];
    }
  }
  const int inf = 2'000'000;
  vector<vector<vector<int>>> d(2, vector<vector<int>>(r, vector<int>(c, inf)));
  priority_queue<Cell> pq;
  pq.emplace(0, 0, 0, 0);
  d[0][0][0] = 0;
  while (!pq.empty()) {
    const auto cell = pq.top();
    pq.pop();
    const auto i = cell.r, j = cell.c, f = cell.f, cd = cell.d;
    if (cell.d == d[f][i][j]) {
      if (i + 1 < r) {
        if (d[0][i + 1][j] > cd + b[i][j]) {
          d[0][i + 1][j] = cd + b[i][j];
          pq.emplace(0, i + 1, j, d[0][i + 1][j]);
        }
      }
      if (j) {
        if (d[0][i][j - 1] > cd + a[i][j - 1]) {
          d[0][i][j - 1]  = cd + a[i][j - 1];
          pq.emplace(0, i, j - 1, d[0][i][j - 1]);
        }
      }
      if (j + 1 < c) {
        if (d[0][i][j + 1] > cd + a[i][j]) {
          d[0][i][j + 1]  = cd + a[i][j];
          pq.emplace(0, i, j + 1, d[0][i][j + 1]);
        }
      }
      if (f) {
        if (i) {
          if (d[1][i - 1][j] > cd + 1) {
            d[1][i - 1][j] = cd + 1;
            pq.emplace(1, i - 1, j, d[1][i - 1][j]);
          }
        }
      } else {
        if (i) {
          if (d[1][i - 1][j] > cd + 2) {
            d[1][i - 1][j] = cd + 2;
            pq.emplace(1, i - 1, j, d[1][i - 1][j]);
          }
        }
      }
    }
  }
  cout << min(d[0][r - 1][c - 1], d[1][r - 1][c - 1]) << "\n";
  return 0;
}
