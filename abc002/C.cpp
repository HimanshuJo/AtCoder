#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t xa, ya, xb, yb, xc, yc;
  cin >> xa >> ya >> xb >> yb >> xc >> yc;
  xb -= xa; xc -= xa; xa = 0; yb -= ya; yc -= ya; ya = 0;
  cout << setprecision(6) << fixed << abs(xb * yc - xc * yb) / 2.0 << "\n";
  return 0;
}