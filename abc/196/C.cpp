#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int64_t n;
  cin >> n;
  int c = 0;
  for (int k = 1; stoll(to_string(k) + to_string(k)) <= n; ++k) {
    ++c;
  }
  cout << c << "\n";
  return 0;
}