#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  string max_name, second_max_name;
  int max_height = -1, second_max_height = -1;
  for (int i = 0; i < n; ++i) {
    string name;
    int height;
    cin >> name >> height;
    if (height > max_height) {
      second_max_height = max_height;
      second_max_name = max_name;
      max_height = height;
      max_name = name;
    } else if (height > second_max_height) {
      second_max_height = height;
      second_max_name = name;
    }
  }
  cout << second_max_name << "\n";
  return 0;
}
