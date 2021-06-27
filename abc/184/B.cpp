#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, x;
  string s;
  cin >> n >> x >> s;
  for (auto c : s) {
    if (c == 'o') {
      ++x;
    } else if (x) {
      --x;
    }
  }
  cout << x << "\n";

  return 0;
}
