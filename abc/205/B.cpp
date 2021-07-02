#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  sort(a.begin(), a.end());
  vector<int> b(n);
  iota(b.begin(), b.end(), 1);
  cout << (a == b ? "Yes" : "No") << "\n";
  return 0;
}