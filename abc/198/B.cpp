#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  string s;
  cin >> s;
  int i = s.length() - 1;
  while (i >= 0 && s[i] == '0') {
    --i;
  }
  s = s.substr(0, i + 1);
  cout << (string(s.rbegin(), s.rend()) == s ? "Yes" : "No") << "\n";
  return 0;
}
