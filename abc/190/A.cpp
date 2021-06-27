#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int a, b, c;
  cin >> a >> b >> c;
  if (c) {
    cout << ((a < b) ? "Aoki" : "Takahashi") << "\n";
  } else {
    cout << ((a > b) ? "Takahashi" : "Aoki") << "\n";
  }

  return 0;
}
