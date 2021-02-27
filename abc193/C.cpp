#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t n;
  cin >> n;
  set<int64_t> r;
  for (int64_t a = 2; a * a <= n; ++a) {
    for (int64_t p = a * a; p <= n; p *= a) {
      r.insert(p);
    }
  }
  cout << n - (int)r.size() << "\n";
  return 0;
}
