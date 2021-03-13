#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int a, b, w;
  cin >> a >> b >> w;
  w *= 1000;
  int l = (w + b - 1) / b, u = w / a;
  if (l > u) {
    cout << "UNSATISFIABLE\n";
  } else {
    cout << l << " " << u << "\n";
  }

  return 0;
}
