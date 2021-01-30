#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m, k;
  cin >> n >> m;
  vector<pair<int, int>> conditions(m);
  for (auto& condition : conditions) {
    cin >> condition.first >> condition.second;
    --condition.first, --condition.second;
  }
  cin >> k;
  vector<pair<int, int>> people(k);
  for (auto& person : people) {
    cin >> person.first >> person.second;
    --person.first, --person.second;
  }

  int best = 0; 
  for (int mask = 0; mask < (1 << k); ++mask) {
    vector<int> balls(n);
    for (int person = 0; person < k; ++person) {
      if (mask & (1 << person)) {
        ++balls[people[person].second];
      } else {
        ++balls[people[person].first];
      }
    }
    int current = 0;
    for (const auto& condition : conditions) {
      if (balls[condition.first] && balls[condition.second]) {
        ++current;
      }
    }
    best = max(best, current);
  }
  cout << best;

  return 0;
}
