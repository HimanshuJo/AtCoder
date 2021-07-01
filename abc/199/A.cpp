#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  cout << (a * a + b * b < c * c ? "Yes" : "No") << "\n";
  return 0;
}