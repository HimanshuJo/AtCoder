#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int64_t n, s, d, xi, yi;
  cin >> n >> s >> d;
  while (n--) {
    cin >> xi >> yi;
    if (s > xi && yi > d) {
      cout << "Yes\n";
      return 0;
    }
  }
  cout << "No\n";
  return 0;
}
