#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update> ordered_set;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, q;
  cin >> n >> q;
  ordered_set r, c;
  r.insert(make_pair(n, n));
  c.insert(make_pair(n, n));
  int64_t a = (n - 2) * 1ll * (n - 2);
  cerr << a << " ";
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 1) {  // column
      auto i = c.order_of_key(make_pair(x, 0));
      auto [nc, nr] = *c.find_by_order(i);
      a -= nr - 2;
      c.insert(make_pair(x, nr));
      if (!i) {
        auto [fr, fc] = *r.find_by_order(0);
        r.erase(make_pair(fr, fc));
        r.insert(make_pair(fr, x));
      }
    } else {  // t == 2  // row
      auto i = r.order_of_key(make_pair(x, 0));
      auto [nr, nc] = *r.find_by_order(i);
      a -= nc - 2;
      r.insert(make_pair(x, nc));
      if (!i) {
        auto [fc, fr] = *c.find_by_order(0);
        c.erase(make_pair(fc, fr));
        c.insert(make_pair(fc, x));
      }
    }
    cerr << a << " ";
  }
  cerr << "\n";
  cout << a << "\n";
  return 0;
}