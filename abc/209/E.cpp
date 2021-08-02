#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(),cerr.tie(0);
  int n;
  cin >> n;
  vector<string> s(n);
  for (auto& si : s) {
    cin >> si;
  }
  auto hash = [] (string s) -> int {
    int h = 0;
    for (auto c : s) {
      h *= 52;
      if ('a' <= c && c <= 'z') {
        h += c - 'a';
      }
      if ('A' <= c && c <= 'Z') {
        h += c - 'A' + 26;
      }
    }
    return h;
  };
  const int mh = 52 * 52 * 52;
  vector<unordered_set<int>> g(mh);
  vector<unordered_set<int>> gr(mh);
  for (auto& si : s) {
    const int l = si.length();
    const int lh = hash(si.substr(0, 3));
    const int rh = hash(si.substr(l - 3));
    g[lh].insert(rh);
    gr[rh].insert(lh);
  }
  vector<int> d(mh);
  for (int h = 0; h < mh; ++h) {
    d[h] = g[h].size();
  }
  vector<bool> winning(mh), losing(mh), u(mh);
  function<void(int)> dfs = [&] (int v) -> void {
    u[v] = true;
    for (auto w : gr[v]) {
      if (!u[w]) {
        if (losing[v]) {
          winning[w] = true;
          dfs(w);
        } else if (--d[w] == 0) {
          losing[w] = true;
          dfs(w);
        }
      }
    }
  };
  for (int h = 0; h < mh; ++h) {
    if (!d[h]) {
      losing[h] = true;
      dfs(h);
    }
  }
  for (auto& si : s) {
    const int l = si.length();
    const int rh = hash(si.substr(l - 3));
    if (winning[rh]) {
      cout << "Aoki";
    } else if (losing[rh]) {
      cout << "Takahashi";
    } else {
      cout << "Draw";
    }
    cout << "\n";
  }
  return 0;
}