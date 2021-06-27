#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t n;
  cin >> n;
  n <<= 1;

  int64_t answer = 0;

  for (int64_t s = 1; s * s <= n; ++s) {
    if (n % s == 0) {
      int64_t d = n / s - 1;
      if ((d & 1) == (s & 1)) {
        ++answer;
      }
    }
  }

  for (int64_t t = 1; t * t < n; ++t) {
    if (n % t == 0) {
      int64_t s = n / t;
      int64_t d = n / s - 1;
      if ((d & 1) == (s & 1)) {
        ++answer;
      }
    }
  }

  cout << answer << "\n";

  return 0;
}
