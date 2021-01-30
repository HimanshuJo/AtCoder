#include <iostream>
#include <vector>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int64_t CountInversions(const vector<int>& a) {
  int64_t answer = 0;
  ordered_set s;
  for (auto ai : a) {
    answer += s.order_of_key(ai);
    s.insert(ai);
  }
  return answer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& ai : a) {
    cin >> ai;
  }

  int64_t answer = CountInversions(a);
  for (int i = 0; i < n; ++i) {
    cout << answer << " ";
    answer = answer - a[i] + n - 1 - a[i];
  }

  return 0;
}
