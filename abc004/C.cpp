#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  n %= 720;
  vector<int> a = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < n; ++i) {
    swap(a[i % 5], a[(i % 5) + 1]);
  }
  for (auto ai : a) {
    cout << ai;
  }
  cout << "\n";
  return 0;
}
