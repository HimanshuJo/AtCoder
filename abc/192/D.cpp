#include <bits/stdc++.h>
using namespace std;
const int64_t inf = 2e18;
int64_t value(string& x, int64_t base) {
  int64_t val = 0;
  for (auto ch : x) {
    if (val > inf / base) {
      return inf;
    }
    val *= base;
    val += ch - '0';
  }
  return val;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string x; int64_t m;
  cin >> x >> m;
  if (x.length() == 1) {
    if (x[0] - '0' <= m) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  } else {
    int d = 0;
    for (auto ch : x) {
      d = max(d, ch - '0');
    }
    // lo always works, hi never works
    int64_t lo = d, hi = m + 1;
    while (lo + 1 < hi) {
      int64_t mi = (lo + hi) >> 1;
      if (value(x, mi) <= m) {
        lo = mi;
      } else {
        hi = mi;
      }
    }
    cout << lo - d << "\n";
  } 
  return 0;
}
