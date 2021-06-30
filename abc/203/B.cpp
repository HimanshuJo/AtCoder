#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, k;
  cin >> n >> k;
  int s = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      s += 100 * i + j;
    }
  }
  cout << s << "\n";
  return 0;
}
