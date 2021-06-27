#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  for (auto ch : s) {
    if (ch != 'a' && ch != 'e' && ch != 'o' && ch != 'i' && ch != 'u') {
      cout << ch;
    }
  }
  cout << "\n";
  return 0;
}