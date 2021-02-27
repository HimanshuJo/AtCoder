#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int a, b;
  cin >> a >> b;
  cout << fixed << setprecision(6) << (a - b) * 100. / a << "\n";
  return 0;
}
