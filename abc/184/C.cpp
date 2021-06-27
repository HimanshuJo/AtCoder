#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int64_t r1, c1, r2, c2;
  cin >> r1 >> c1 >> r2 >> c2;

  if (r1 == r2 && c1 == c2) {
    cout << 0;
  } else if (std::abs(r1 - r2) + std::abs(c1 - c2) <= 3 ||
             r1 - c1 == r2 - c2 || r1 + c1 == r2 + c2) {
    cout << 1;
  } else if ((std::abs(r1 - r2) & 1) == (std::abs(c1 - c2) & 1) ||
             std::abs(r1 - r2) + std::abs(c1 - c2) <= 6 ||
             std::abs((r1 - c1) - (r2 - c2)) <= 3 ||
             std::abs((r1 + c1) - (r2 + c2)) <= 3) {
    cout << 2;
  } else {
    cout << 3;
  }
  cout << "\n";

  return 0;
}
