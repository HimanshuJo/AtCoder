#include <algorithm>
#include <iostream>
#include <vector>

int LCS(const std::vector<int>& a, const std::vector<int>& b, int n, int m) { 
  std::vector<std::vector<int>> lcs(n + 1, std::vector<int>(m + 1, n + m));
  lcs[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    lcs[i][0] = i;
  }
  for (int j = 1; j <= m; ++j) {
    lcs[0][j] = j;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i - 1] == b[j - 1]) {
        lcs[i][j] = lcs[i - 1][j - 1];
      }
      lcs[i][j] = std::min(lcs[i][j],
        1 + std::min({lcs[i - 1][j], lcs[i][j - 1], lcs[i - 1][j - 1]}));
    }
  } 
  return lcs[n][m]; 
} 

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n), b(m);
  for (auto& ai : a) {
    std::cin >> ai;
  }
  for (auto& bj : b) {
    std::cin >> bj;
  }
  std::cout << LCS(a, b, n, m);

  return 0;
}
