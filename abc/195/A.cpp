#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int m, h;
  cin >> m >> h;
  cout << ((h % m) ? "No" : "Yes") << "\n";

  return 0;
}
