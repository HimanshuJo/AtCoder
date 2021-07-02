#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, k;
  cin >> n >> k;
  vector t(n, vector(n, 0));
  for (auto& ti : t) {
    for (auto& tij : ti) {
      cin >> tij;
    }
  }
  vector p(n, 0);
  iota(p.begin(), p.end(), 0);
  int c = 0;
  do {
    int s = 0;
    for (int i = 0; i < n; ++i) {
      s += t[p[i]][p[(i + 1) % n]];
    }
    if (s == k) {
      ++c;
    }
  } while (next_permutation(next(p.begin()), p.end()));
  cout << c << "\n";
  return 0;
}