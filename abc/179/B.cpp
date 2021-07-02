#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  int ccd = 0;
  bool j = false;
  while (n--) {
    int d1, d2;
    cin >> d1 >> d2;
    if (d1 == d2) {
      ++ccd;
    } else {
      ccd = 0;
    }
    j |= ccd == 3;
  }
  cout << (j ? "Yes" : "No") << "\n";
  return 0;
}