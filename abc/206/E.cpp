#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int l, r;
  cin >> l >> r;


  // # (x, y)
  // (1) L <= x, y <= R
  // (2) g = gcd(x, y)
  // (3) g != 1
  // (4) g != x
  // (5) g != y


  // # (g, x', y')
  // (1)   L/g <= x', y' <= R/g
  // (2)   gcd(x', y') = 1
  // (3-5) g, x', y' != 1


  // Loop over g in 2..N:
  //   # (x', y')
  //   (1) L/g <= x', y' <= R/g
  //   (2) gcd(x', y') = 1
  //   (3) x', y' != 1


  // // These two loops are O(N log N) overall, just like sieve
  // Loop over g in 2..N:
  //   Loop over x' in max(2, ceil(L/g))..floor(R/g):
  //     # y'
  //     (1) L/g <= y' <= R/g
  //     (2) gcd(x', y') = 1
  //     (3) y' != 1


  // def upto(g, x', R):
  //   # y'
  //   (1) y' <= R/g
  //   (2) gcd(x', y') = 1
  //   (3) y' != 1

  // cnt = 0
  // Loop over g in 2..N:
  //   Loop over x' in max(2, ceil(L/g))..floor(R/g):
  //      cnt += upto(g, x', R) - upto(g, x', L - 1)


  // How fast should upto() be? O(1) or O(log N)?

  auto upto = [&] (int g, int x, int r) -> int {
    
  };

  const int N = 1'000'001;
  int64_t cnt = 0;
  for (int g = 2; g < N; ++g) {
    for (int x = max(2, (L + g - 1) / g); x <= R / g; ++x) {
      cnt += upto(g, x, R) - upto(g, x, L - 1);
    }
  }
  cout << cnt << "\n";

  return 0;
}