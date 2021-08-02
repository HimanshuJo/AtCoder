#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  string s;
  cin >> s;
  const int N = 4;

  bool same = false;
  for (int first = 0; first < 10; ++first) {
    bool all = true;
    for (int i = 0; i < N; ++i) {
      all &= (first == s[i] - '0'); 
    }
    same |= all;
  }

  bool follow = false;
  for (int first = 0; first < 10; ++first) {
    bool all = true;
    for (int i = 0; i < N; ++i) {
      all &= ((first + i) % 10 == s[i] - '0'); 
    }
    follow |= all;
  }

  bool weak = same || follow;
  if (weak) {
    cout << "Weak";
  } else {
    cout << "Strong";
  }
  cout << "\n";

  return 0;
}