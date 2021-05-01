#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  deque<char> t;
  bool r = false;
  string s;
  cin >> s;
  for (auto c : s) {
    if (c == 'R') {
      r = !r;
    } else {
      if (r) {
        t.push_front(c);
      } else {
        t.push_back(c);
      }
    }
  }
  if (r) {
    reverse(t.begin(), t.end());
  }
  deque<char> st;
  for (auto c : t) {
    if (!st.empty() && st.back() == c) {
      st.pop_back();
    } else {
      st.push_back(c);
    }
  }
  for (auto c : st) {
    cout << c;
  }
  cout << "\n";
  return 0;
}
