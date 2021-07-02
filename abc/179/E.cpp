#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int64_t n; int x, m;
  cin >> n >> x >> m;
  unordered_set<int> u;
  vector<int> a = {x};
  while (!u.count(x)) {
    u.insert(x);
    x = (x * 1ll * x) % m;
    a.push_back(x);
  }
  auto it = find(a.begin(), a.end(), a.back());
  a.pop_back();
  auto i = distance(a.begin(), it);
  auto j = a.size() - i;
  auto s = accumulate(a.begin(), it, 0ll);
  n -= i;
  auto [k, l] = div(n, j);
  s += k * accumulate(it, a.end(), 0ll);
  s += accumulate(it, next(it, l), 0ll);
  cout << s << "\n";
  return 0;
}