#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  if (c & 1) {
    if (a < 0) {
      if (b < 0) {
        cout << (a == b ? "=" : a > b ? ">" : "<") << "\n";
      } else {
        cout << "<" << "\n";
      }
    } else {
      if (b < 0) {
        cout << ">" << "\n";
      } else {
        cout << (a == b ? "=" : a > b ? ">" : "<") << "\n";
      }
    }
  } else {
    a = abs(a);
    b = abs(b);
    cout << (a == b ? "=" : a > b ? ">" : "<") << "\n";
  }
  return 0;
}