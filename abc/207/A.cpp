#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  const int n = 3;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  sort(a.begin(), a.end());
  cout << accumulate(next(a.begin()), a.end(), 0) << "\n";
  return 0;
}