#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (auto c : s) {
    if (c == '0' || c == '1' || c == '8') {
      cout << c;
    } else if (c == '6') {
      cout << '9';
    } else {
      cout << '6';
    }
  }
  cout << "\n";
  return 0;
}
