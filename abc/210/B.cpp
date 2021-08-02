#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  string s;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      cout << ((i & 1) ? "Aoki" : "Takahashi") << "\n";
      break;
    }
  }
  return 0;
}