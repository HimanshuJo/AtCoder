#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  string s;
  cin >> s;
  cout << s + (s.back() == 's' ? "es" : "s") << "\n";
  return 0;
}