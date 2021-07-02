#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int a, b;
  cin >> a >> b;
  cout << fixed << setprecision(10) << (a / 100.) * b << "\n";
  return 0;
}