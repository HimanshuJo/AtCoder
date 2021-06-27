#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }

  auto divisors = [&] (int ai) -> vector<int> {
    vector<int> di;
    for (int d = 1; d * d <= ai; ++d) {
      if (ai % d == 0) {
        di.push_back(d);
        if (d * d != ai) {
          di.push_back(ai / d);
        }
      }
    }
    return di;
  };

  unordered_map<int, int> mp;
  for (auto ai : a) {
    for (auto dij : divisors(ai)) {
      if (mp.count(dij)) {
        mp[dij] = gcd(mp[dij], ai);
      } else {
        mp[dij] = ai;
      }
    }
  }

  int c = 0, m = *min_element(a.begin(), a.end());
  for (auto [k, v] : mp) {
    if (k == v && v <= m) {
      ++c;
    }
  }
  cout << c << "\n";

  return 0;
}
