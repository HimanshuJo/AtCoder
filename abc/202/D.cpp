#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int a, b;
  int64_t k;
  cin >> a >> b >> k;
  vector<vector<int64_t>> ways(a + 1, vector<int64_t>(b + 1));
  ways[0][0] = 1;
  for (int i = 0; i < a; ++i) {
    ways[i + 1][0] = 1;
  }
  for (int j = 0; j < b; ++j) {
    ways[0][j + 1] = 1;
  }
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < b; ++j) {
      ways[i + 1][j + 1] = ways[i + 1][j] + ways[i][j + 1];
    }
  }
  while (a || b) {
    if (a) {
      if (b) {
        if (ways[a - 1][b] >= k) {
          cout << 'a';
          --a;
        } else {
          k -= ways[a - 1][b];
          cout << 'b';
          --b;
        }
      } else {
        cout << 'a';
        --a;
      }
    } else {
      cout << 'b';
      --b;
    }
  }
  return 0;
}
