#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  long double d, h;
  cin >> n >> d >> h;
  long double a = 0;
  for (int i = 0; i < n; ++i) {
    long double di, hi;
    cin >> di >> hi;
    a = max(a, hi - (h - hi) / (d - di) * di);
  }
  cout << setprecision(10) << fixed << a << "\n";
  return 0;
}
