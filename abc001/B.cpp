#include <bits/stdc++.h>
using namespace std;
int main() {
  int d;
  cin >> d;
  if (d < 100) {
    cout << "00\n";
  } else if (d <= 5'000) {
    d /= 100;
    if (d < 10) {
      cout << "0";
    }
    cout << d << "\n";
  } else if (d <= 30'000) {
    d /= 1'000;
    cout << d + 50 << "\n"; 
  } else if (d <= 70'000) {
    d -= 30'000;
    d /= 5'000;
    cout << 80 + d << "\n";
  } else {
    cout << "89\n";
  }
  return 0;
}
