#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> se(n);
  for (auto& [s, e] : se) {
    {
      cin >> s;
      auto [q, r] = div(s, 100);
      s = 60 * q + r;
    }
    cin.ignore();
    {
      cin >> e;
      auto [q, r] = div(e, 100);
      e = 60 * q + r;
    }
  }
  vector<pair<int, int>> events;
  for (auto [s, e] : se) {
    events.emplace_back((s / 5) * 5, -1);
    events.emplace_back(((e + 4) / 5) * 5, 1);
  }
  sort(events.begin(), events.end());
  vector<pair<int, int>> interval_union;
  int interval_count = 0;
  for (auto [time, type] : events) {
    if (!interval_count) {
      interval_union.emplace_back(time, time);
    } else {
      interval_union.back().second = time;
    }
    interval_count -= type;
  }
  auto str = [] (int n) -> string {
    string s;
    if (n < 600) {
      s += "0";
    }
    if (n < 60) {
      s += "0";
    }
    if (n < 10) {
      s += "0";
    }
    auto [q, r] = div(n, 60);
    s += to_string(100 * q + r);
    return s;
  };
  for (auto [s, e] : interval_union) {
    cout << str(s) << "-" << str(e) << "\n";
  }
  return 0;
}
