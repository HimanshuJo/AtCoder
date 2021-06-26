#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t a, b, c, d;
  cin >> a >> b >> c >> d;
  if (d * c <= b) {
    cout << -1 << "\n";
  } else {
    int64_t den = d * c - b;
    cout << (a + den - 1) / den << "\n";
  }
  return 0;
}