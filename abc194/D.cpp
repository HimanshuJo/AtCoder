#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  long double e = 0;
  for (int i = 1; i < n; ++i) {
    e += 1. / i;
  }
  cout << fixed << setprecision(10) << n * e << "\n";
  return 0;
}
