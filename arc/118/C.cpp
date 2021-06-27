#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << "6 10 15\n";
  } else {
    set<int> a;
    for (int i = 6; i <= 10'000; i += 6) {
      a.insert(i);
    }
    for (int i = 10; i <= 10'000; i += 10) {
      a.insert(i);
    }
    for (int i = 15; i <= 10'000; i += 15) {
      a.insert(i);
    }
    vector<int> b(a.begin(), next(a.begin(), n));
    for (auto bi : b) {
      cout << bi << " ";
    }
    cout << "\n";
  }
  return 0;
}
