#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, ai;
  cin >> n;
  int64_t a = 0;
  vector<int> f(200);
  for (int i = 0; i < n; ++i) {
    cin >> ai;
    ai %= 200;
    a += f[ai];
    ++f[ai];
  }
  cout << a << "\n";
  return 0;
}