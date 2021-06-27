#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t p, a, b;
  cin >> p >> a >> b;
  vector<vector<int64_t>> c;
  c.emplace_back();
  c.back().push_back(1);
  set<int64_t> s;
  s.insert(1);
  int64_t i = 1, j = 0;
  do {
    do {  // column
      c[j].push_back((c[j].back() * a) % p);
      s.insert(c[j].back());
      ++i;
    } while (c[j].back() != c[j][0]);
    c[j].pop_back();
    --i;

    c.emplace_back();
    c.back().push_back((c[j][0] * b) % p);
    s.insert(c.back().back());
    ++i;
    ++j;
  } while (i < p);
  c.pop_back();
  --i;

  const int64_t n = c.size(), m = c[0].size();
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j < m; ++j) {
  //     cout << c[i][j] << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  if (s.size() != p - 1) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
    if (n == 2) {
      cout << 1;
      for (int i = 0; i < m; ++i) {
        cout << " " << c[1][i];
      }
      for (int i = m - 1; i >= 0; --i) {
        cout << " " << c[0][i];
      }
    } else if (n % 2 == 0) {
      cout << 1;
      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {  // even row
          for (int j = 1; j < m; ++j) {
            cout << " " << c[i][j];
          }
        } else {  // odd row
          for (int j = m - 1; j >= 1; --j) {
            cout << " " << c[i][j];
          }
        }
      }
      for (int i = n - 1; i >= 0; --i) {
        cout << " " << c[i][0];
      }
    } else {  // m % 2 == 0
      // list(zip(*matrix)) -- transposes matrix in python
      cout << 1;
      for (int i = 0; i < m; ++i) {
        if (i % 2 == 0) {  // even column
          for (int j = 1; j < n; ++j) {
            cout << " " << c[j][i];
          }
        } else {  // odd column
          for (int j = n - 1; j >= 1; --j) {
            cout << " " << c[j][i];
          }
        }
      }
      for (int i = m - 1; i >= 0; --i) {
        cout << " " << c[0][i];
      }
    }
  }
  return 0;
}
