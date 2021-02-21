#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t k;
  cin >> k;
  int64_t count = 0;
  const int64_t max_k = 200'000;
  vector<int64_t> ab(max_k + 1);
  for (int64_t a = 1; a <= max_k; ++a) {
    for (int64_t b = 1; b * a <= max_k; ++b) {
      ++ab[a * b];
    }
  }
  partial_sum(ab.begin(), ab.end(), ab.begin());
  for (int64_t c = 1; c <= k; ++c) {
    count += ab[k / c];
  }
  cout << count << "\n";
  return 0;
}
