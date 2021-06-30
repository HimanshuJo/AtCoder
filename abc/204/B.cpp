#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  int c = 0;
  for (auto ai : a) {
    c += max(0, ai - 10);
  }
  cout << c << "\n";
  return 0;
}