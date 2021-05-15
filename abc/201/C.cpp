#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  auto good = [&] (int password) -> bool {
    unordered_set<int> digits;
    for (int digit = 0; digit < 4; ++digit) {
      digits.insert(password % 10);
      password /= 10;
    }
    for (int digit = 0; digit < 10; ++digit) {
      if (s[digit] == 'x') {
        if (digits.count(digit)) {
          return false;
        }
      } else if (s[digit] == 'o') {
        if (!digits.count(digit)) {
          return false;
        }
      }
    }
    return true;
  };
  int count = 0;
  for (int password = 0; password < 10000; ++password) {
    if (good(password)) {
      ++count;
    }
  }
  cout << count << "\n";
  return 0;
}
