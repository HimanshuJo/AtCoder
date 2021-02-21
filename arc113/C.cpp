#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  string s;
  cin >> s;
  vector<int> freq(26);
  int64_t count = 0, length = s.length();
  ++freq[s[length - 1] - 'a'];
  ++freq[s[length - 2] - 'a'];
  for (int index = length - 3; index >= 0; --index) {
    ++freq[s[index] - 'a'];
    if (s[index] == s[index + 1] && s[index + 1] != s[index + 2]) {
      count += (length - index - freq[s[index] - 'a']);
      freq.assign(26, 0);
      freq[s[index] - 'a'] = length - index;
      // s[index + 2] = s[index + 1];
    }
  }
  cout << count << "\n";
  return 0;
}
