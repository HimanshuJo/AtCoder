#include <bits/stdc++.h>
using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  long double n, x0, y0, xn, yn;
  cin >> n >> x0 >> y0 >> xn >> yn;

  complex<long double> z(xn - x0, yn - y0);
  auto a = (n - 2) / (2 * n) * M_PI;

  // scale
  z *= sinl(M_PI / n);

  // rotate
  z /= complex<long double>(cosl(a), sinl(a));

  cout << fixed << setprecision(10) << z.real() + x0 << " " << z.imag() + y0 << "\n";

  return 0;
}
