#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cerr.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto& ai : a) {
    cin >> ai;
  }
  for (auto& bi : b) {
    cin >> bi;
  }
  int Ma = *max_element(a.begin(), a.end()), mb = *min_element(b.begin(), b.end());
  cout << max(0, mb - Ma + 1) << "\n";
  return 0;
}