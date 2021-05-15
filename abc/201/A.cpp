#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  vector<int> a(3);
  for (auto& ai : a) {
    cin >> ai;
  }
  sort(a.begin(), a.end());
  if (a[2] - a[1] == a[1] - a[0]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
