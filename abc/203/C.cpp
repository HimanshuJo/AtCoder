#include <bits/stdc++.h>
using namespace std;
struct Friend {
  int64_t a; int b;
  Friend(int64_t a_ = 0, int b_ = 0) : a(a_), b(b_) { }
  bool operator<(const Friend& other) const {
    return make_pair(a, b) < make_pair(other.a, other.b);
  }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t n, k;
  cin >> n >> k;
  vector<Friend> fs(n);
  for (auto& f : fs) {
    cin >> f.a >> f.b;
  }
  sort(fs.begin(), fs.end());
  for (auto f : fs) {
    if (f.a <= k) {
      k += f.b;
    } else {
      break;
    }
  }
  cout << k << "\n";
  return 0;
}
