#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  rotate(s.begin(), next(s.begin()), s.end());
  cout << s << "\n";
  return 0;
}
