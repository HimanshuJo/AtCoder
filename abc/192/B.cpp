#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  bool hard = true;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (i & 1) {
      hard &= ('A' <= s[i] && s[i] <= 'Z');
    } else {
      hard &= ('a' <= s[i] && s[i] <= 'z');
    }
  }
  cout << (hard ? "Yes" : "No") << "\n";
  return 0;
}
