#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int v, t, s, d;
  cin >> v >> t >> s >> d;
  cout << ((v * t <= d && d <= v * s) ? "No" : "Yes") << "\n";
  return 0;
}
