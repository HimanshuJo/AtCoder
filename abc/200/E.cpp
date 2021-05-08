#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  int64_t k;
  cin >> n >> k;
  // sum > beauty > taste

  // find sum
  vector<int64_t> sum(3 * n - 2);
  for (int i = 0; i < n; ++i) {
    sum[i] = ((i + 2ll) * (i + 1ll)) / 2;
  }
  for (int i = n; i < 2 * n; ++i) {
    sum[i] = ((i + 2ll) * (i + 1ll)) / 2 - 3 * sum[i - n];
  }
  for (int i = 0; i < n; ++i) {
    sum[3 * (n - 1) - i] = ((i + 2ll) * (i + 1ll)) / 2;
  }
  partial_sum(sum.begin(), sum.end(), sum.begin());
  auto it = lower_bound(sum.begin(), sum.end(), k);
  auto target_sum = distance(sum.begin(), it);
  if (it != sum.begin()) {
    k -= *prev(it);
  }

  // find beauty
  vector<int64_t> beauty(n);
  for (int i = 0; i < n; ++i) {
    int min_j = max<int64_t>(0, target_sum - i - (n - 1));
    int max_j = min<int64_t>(n - 1, target_sum - i);
    if (max_j >= min_j) {
      beauty[i] = max_j - min_j + 1;
    }
  }
  partial_sum(beauty.begin(), beauty.end(), beauty.begin());
  it = lower_bound(beauty.begin(), beauty.end(), k);
  auto target_beauty = distance(beauty.begin(), it);
  if (it != beauty.begin()) {
    k -= *prev(it);
  }

  // find taste
  int min_j = max<int64_t>(0, target_sum - target_beauty - (n - 1));
  auto target_taste = min_j + k - 1;
  auto target_popularity = target_sum - target_beauty - target_taste;
  cout << target_beauty + 1 << " " << target_taste + 1 << " " << target_popularity + 1 << "\n";

  return 0;
}
