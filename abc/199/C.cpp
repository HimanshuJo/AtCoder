#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, q;
  string s;
  cin >> n >> s >> q;
  bool f = false;
  auto p = [&] (int i) -> int {
    if (f) {
      if (i < n) {
        return i + n;
      } else {
        return i - n;
      }
    } else {
      return i;
    }
  };
  while (q--) {
    int t, a, b;
    cin >> t >> a >> b;
    if (t == 1) {
      --a, --b;
      swap(s[p(a)], s[p(b)]);
    } else {  // t == 2
      assert(a == 0 && b == 0);
      f = !f;
    }
  }
  for (int i = 0; i < (n << 1); ++i) {
    cout << s[p(i)];
  }
  cout << "\n";
  return 0;
}