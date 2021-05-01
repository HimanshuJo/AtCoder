#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  const int n = s.length();
  int count = 0;
  for (int i = 0; i + 4 <= n; ++i) {
    if (s.substr(i, 4) == "ZONe") {
      ++count;
    }
  }
  cout << count << "\n";
  return 0;
}
