#include <bits/stdc++.h>
using namespace std;

enum EventType {
  kBusStart = 1,
  kBusEnd = 0,
  kQueryStart = 2,
  kQueryEnd = 3,
};

enum LocationType {
  kCity = 4,
  kBus = 5,
};

int main() {
  ios::sync_with_stdio(0),cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<tuple<int, int, int, int>> abst(m);
  for (auto& [a, b, s, t] : abst) {
    cin >> a >> b >> s >> t;
    --a, --b;
  }
  vector<tuple<int, int, int>> xyz(q);
  for (auto& [x, y, z] : xyz) {
    cin >> x >> y >> z;
    --y;
  }

  vector<tuple<int, int, EventType>> events;
  for (int i = 0; i < m; ++i) {
    auto [a, b, s, t] = abst[i];
    events.emplace_back(2 * s + 1, i, kBusStart);
    events.emplace_back(2 * t + 1, i, kBusEnd);
  }
  for (int j = 0; j < q; ++j) {
    auto [x, y, z] = xyz[j];
    events.emplace_back(2 * x, j, kQueryStart);
    events.emplace_back(2 * z, j, kQueryEnd);
  }
  sort(events.begin(), events.end(), [&] (const auto& a, const auto& b) -> bool {
    return make_tuple(get<0>(a), get<2>(a)) < make_tuple(get<0>(b), get<2>(b));
  });

  using Location = pair<int, LocationType>;
  using ptr = vector<int>*;
  map<Location, ptr> whoat;
  for (int i = 0; i < n; ++i) {
    whoat[{i, kCity}] = new vector<int>();
  }
  for (int j = 0; j < m; ++j) {
    whoat[{j, kBus}] = new vector<int>();
  }
  auto merge = [&] (ptr a, ptr b) -> ptr {
    if (a->size() < b->size()) {
      swap(a, b);
    }
    for (auto c : *b) {
      a->push_back(c);
    }
    // delete b;
    return a;
  };

  vector<Location> where(q); 
  vector<int> parent(q), rank(q);
  for (int j = 0; j < q; ++j) {
    parent[j] = j;
  }
  function<int(int)> Find = [&] (int i) -> int {
    return parent[i] == i ? i : parent[i] = Find(parent[i]);
  };
  auto Union = [&] (int i, int j) -> void {
    i = Find(i), j = Find(j);
    if (i != j) {
      if (rank[i] < rank[j]) {
        swap(i, j);
      }
      parent[j] = i;
      if (rank[i] == rank[j]) {
        ++rank[i];
      }
    }
  };

  vector<Location> ans(q);
  for (auto [tm, k, type] : events) {
    if (type == kBusStart) {
      auto [a, b, s, t] = abst[k];
      if (!whoat[{a, kCity}]->empty()) {
        auto i = whoat[{a, kCity}]->back();
        if (!whoat[{k, kBus}]->empty()) {
          auto j = whoat[{k, kBus}]->back();
          Union(i, j);
          where[Find(j)] = {k, kBus};
        }
        where[Find(i)] = {k, kBus};
        whoat[{k, kBus}] = merge(whoat[{a, kCity}], whoat[{k, kBus}]);
        whoat[{a, kCity}] = new vector<int>();
      }
    } else if (type == kBusEnd) {
      auto [a, b, s, t] = abst[k];
      if (!whoat[{k, kBus}]->empty()) {
        auto j = whoat[{k, kBus}]->back();
        if (!whoat[{b, kCity}]->empty()) {
          auto i = whoat[{b, kCity}]->back();
          Union(i, j);
          where[Find(i)] = {b, kCity};
        }
        where[Find(j)] = {b, kCity};
        whoat[{b, kCity}] = merge(whoat[{b, kCity}], whoat[{k, kBus}]);
        whoat[{k, kBus}] = new vector<int>();
      }
    } else if (type == kQueryStart) {
      auto [x, y, z] = xyz[k];
      if (!whoat[{y, kCity}]->empty()) {
        auto i = whoat[{y, kCity}]->back();
        Union(i, k);
        where[Find(i)] = {y, kCity};
      }
      where[Find(k)] = {y, kCity};
      whoat[{y, kCity}]->push_back(k);
    } else {  // type == kQueryEnd
      ans[k] = where[Find(k)];
    }
  }

  for (auto [k, type] : ans) {
    if (type == kCity) {
      cout << k + 1 << "\n";
    } else {  // type == kBus
      auto [a, b, s, t] = abst[k];
      cout << a + 1 << " " << b + 1 << "\n";
    }
  }

  return 0;
}