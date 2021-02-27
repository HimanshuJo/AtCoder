#include <bits/stdc++.h>
using namespace std;
vector<int> power10 = {1, 10, 100, 1'000, 10'000, 100'000, 1'000'000};
int score(string& s) {
  vector<int> a(10);
  for (auto c : s) {
    ++a[c - '0'];
  }
  int r = 0;
  for (int i = 0; i < 10; ++i) {
    r += i * power10[a[i]];
  }
  return r;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int k;
  string s, t;
  cin >> k >> s >> t;
  vector<int> remains(10, k);
  remains[0] = 0;
  int r = 9 * k;
  for (auto c : s) {
    if (c != '#') {
      --remains[c - '0'];
      --r;
    }
  }
  for (auto c : t) {
    if (c != '#') {
      --remains[c - '0'];
      --r;
    }
  }
  int64_t p = 0;
  for (int i = 1; i < 10; ++i) {
    if (remains[i]) {
      s[4] = i + '0';
      int64_t pi = remains[i];
      --remains[i];
      for (int j = 1; j < 10; ++j) {
        if (remains[j]) {
          t[4] = j + '0';
          int64_t pj = remains[j];
          if (score(s) > score(t)) {
            p += pi * pj;
          }
        }
      }
      ++remains[i];
    }
  }
  cout << fixed << setprecision(10) << p / (r * (r - 1.)) << "\n";
  return 0;
}
