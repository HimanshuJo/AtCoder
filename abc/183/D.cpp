#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n, w;
  cin >> n >> w;
  vector<tuple<int, int, int>> stp(n);
  for (auto& [s, t, p] : stp) {
    cin >> s >> t >> p;
  }
  vector<tuple<int, bool, int>> top;
  for (auto [s, t, p] : stp) {
    top.emplace_back(s, true, p);
    top.emplace_back(t, false, p);
  }
  sort(top.begin(), top.end());
  bool f = true;
  int64_t ps = 0;
  for (auto [_, o, p] : top) {
    if (o) {
      ps += p;
    } else {
      ps -= p;
    }
    if (ps > w) {
      f = false;
    }
  }
  cout << (f ? "Yes" : "No") << "\n";
  return 0;
}