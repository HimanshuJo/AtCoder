#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(),cerr.tie(0);
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  int s = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      s += a[i] - 1;
    } else {
      s += a[i];
    }
  }
  cout << (x >= s ? "Yes" : "No") << "\n";
  return 0;
}