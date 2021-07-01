#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  string x;
  cin >> x;
  if (x.find('.') != string::npos) {
    x.erase(x.find('.'));
  }
  cout << x << "\n";
  return 0;
}