#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  multiset<int> ms;
  for (int i = 0; i < (1 << n); ++i) {
    int si;
    cin >> si;
    ms.insert(si);
  }
  multiset<int> s;
  auto it = prev(ms.end());
  s.insert(*it);
  ms.erase(it);
  for (int i = 0 ; i < n; ++i) {
    multiset<int> ns(s.begin(), s.end());
    for (auto si : s) {
      auto it = ms.lower_bound(si);
      if (it == ms.begin()) {
        cout << "No\n";
        return 0;
      }
      --it;
      ns.insert(*it);
      ms.erase(it);
    }
    swap(s, ns);
  }
  cout << "Yes\n";
  return 0;
}