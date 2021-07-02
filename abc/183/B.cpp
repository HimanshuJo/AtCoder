#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  long double sx, sy, gx, gy;
  cin >> sx >> sy >> gx >> gy;
  gy = -gy;
  long double slope = (gy - sy) / (gx - sx);
  cout << fixed << setprecision(10) << sx - sy / slope << "\n";
  return 0;
}