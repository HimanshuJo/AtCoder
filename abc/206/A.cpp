#include <bits/stdc++.h>
using namespace std;
const string kLessThan = "Yay!", kEqualTo = "so-so", kMoreThan = ":(";
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  int p = (108 * n) / 100;
  const int kListPrice = 206;
  if (p < kListPrice) {
    cout << kLessThan;
  } else if (p == kListPrice) {
    cout << kEqualTo;
  } else {
    cout << kMoreThan;
  }
  cout << "\n";
  return 0;
}
