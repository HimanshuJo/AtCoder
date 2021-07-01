#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  vector<string> ss(3);
  for (auto& s : ss) {
    cin >> s;
  }
  unordered_map<char, int> mp;
  for (auto s : ss) {
    for (auto c : s) {
      if (!mp.count(c)) {
        mp[c] = mp.size();
      }
    }
  }
  if (mp.size() > 10) {
    cout << "UNSOLVABLE\n";
    return 0;
  }
  bool f = false;
  vector<int> digits(10);
  iota(digits.begin(), digits.end(), 0);
  do {
    vector<int64_t> r(3);
    for (int i = 0; i < 3; ++i) {
      for (auto c : ss[i]) {
        r[i] = 10 * r[i] + digits[mp[c]];
      }
    }
    if (digits[mp[ss[0][0]]] &&
        digits[mp[ss[1][0]]] &&
        digits[mp[ss[2][0]]] &&
        r[0] + r[1] == r[2]) {
      for (auto ri : r) {
        cout << ri << "\n";
      }
      f = true;
    }
  } while (!f && next_permutation(digits.begin(), digits.end()));
  if (!f) {
    cout << "UNSOLVABLE\n";
  }
  return 0;
}
