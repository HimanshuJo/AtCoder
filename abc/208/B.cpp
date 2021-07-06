#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int p;
  cin >> p;
  vector<int> f = {1};
  for (int i = 2; f.back() < p; ++i) {
    f.push_back(i * f.back());
  }
  int c = 0;
  while (!f.empty()) {
    auto [q, r] = div(p, f.back());
    c += q;
    p = r;
    f.pop_back();
  }
  cout << c << "\n";
  return 0;
}