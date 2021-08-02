#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);

  int64_t delta = 0;
  multiset<int64_t> ms;

  int q; cin >> q; while (q--) {
    int tp;
    cin >> tp;
    if (tp == 1) {
      int xi;
      cin >> xi;
      ms.insert(xi - delta);
    } else if (tp == 2) {
      int xi;
      cin >> xi;
      delta += xi;
    } else {  // tp == 3
      auto it = ms.begin();
      cout << *it + delta << "\n";
      ms.erase(it);
    }
  }

  return 0;
}