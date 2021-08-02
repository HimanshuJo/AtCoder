#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int h, w, c;
  cin >> h >> w >> c;
  vector<vector<int>> a(h, vector<int>(w));
  for (auto& ai : a) {
    for (auto& aij : ai) {
      cin >> aij;
    }
  }
  // TODO
  return 0;
}