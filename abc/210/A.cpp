#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n, a, x, y;
  cin >> n >> a >> x >> y;
  int nx = min(a, n);
  int ny = n - nx;
  cout << nx * x + ny * y << "\n";
  return 0;
}