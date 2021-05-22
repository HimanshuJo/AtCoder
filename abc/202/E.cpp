#include <bits/stdc++.h>
using namespace std;
using ans = unordered_map<int, int>;
using pans = ans*;
pans merge(pans first, pans second) {
  if (first->size() < second->size()) {
    swap(first, second);
  }
  for (auto [k, v] : *second) {
    (*first)[k] += v;
  }
  return first;
}
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<vector<int>> graph(n);
  for (int i = 1, pi; i < n; ++i) {
    cin >> pi;
    --pi;
    graph[pi].push_back(i);
  }
  int q;
  cin >> q;
  unordered_map<int, vector<pair<int, int>>> qs;
  for (int i = 0, ui, di; i < q; ++i) {
    cin >> ui >> di;
    --ui;
    qs[ui].emplace_back(di, i);
  }
  vector<int> a(q);
  function<pans(int, int)> dfs = [&] (int vertex, int depth) -> pans {
    auto f = new ans();
    (*f)[depth] = 1;
    for (auto child : graph[vertex]) {
      f = merge(f, dfs(child, depth + 1));
    }
    for (auto [di, i] : qs[vertex]) {
      a[i] = (*f)[di];
    }
    return f;
  };
  dfs(0, 0);
  for (auto elem : a) {
    cout << elem << "\n";
  } 
  return 0;
}
