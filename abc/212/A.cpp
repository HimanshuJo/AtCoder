#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int a, b;
  cin >> a >> b;
  if (a == 0) {
    cout << "Silver";
  } else if (b == 0) {
    cout << "Gold";
  } else {
    cout << "Alloy";
  }
  cout << "\n";
  return 0;
}