#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m + 2);
  a[0] = -1;
  for (int i = 1; i <= m; ++i) {
    std::cin >> a[i];
    --a[i];
  }
  a[m + 1] = n;
  std::sort(a.begin(), a.end());

  int min = n + 1;
  for (int i = 1; i <= m + 1; ++i) {
    if (a[i] != a[i - 1] + 1) {
      min = std::min(min, a[i] - a[i - 1] - 1);
    }
  }

  int ans = 0;
  for (int i = 1; i <= m + 1; ++i) {
    ans += (a[i] - a[i - 1] - 1 + min - 1) / min;
  }
  std::cout << ans << "\n";

  return 0;
}
