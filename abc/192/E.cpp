#include <bits/stdc++.h>
using namespace std;
const int64_t kInfinity = std::numeric_limits<int64_t>::max();
struct Edge {
  int64_t source, destination, time, interval;
  Edge(int64_t s, int64_t d, int64_t t, int64_t i)
    : source(s), destination(d), time(t), interval(i) { }
};
using Graph = vector<vector<Edge>>;
int64_t DijkstraHeap(const Graph& graph, int64_t source, int64_t destination);
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int64_t n, m, x, y;
  cin >> n >> m >> x >> y;
  --x, --y;
  Graph g(n);
  while (m--) {
    int64_t source, destination, time, interval;
    cin >> source >> destination >> time >> interval;
    --source, --destination;
    g[source].emplace_back(source, destination, time, interval);
    g[destination].emplace_back(destination, source, time, interval);
  }
  cout << DijkstraHeap(g, x, y) << "\n";
  return 0;
}
int64_t DijkstraHeap(const Graph& graph, int64_t source, int64_t destination) {
  const int64_t vertex_count = graph.size();
  std::vector<int64_t> distance(vertex_count, kInfinity);
  distance[source] = 0;
  std::priority_queue<std::pair<int64_t, int64_t>,
                      std::vector<std::pair<int64_t, int64_t>>,
                      std::greater<std::pair<int64_t, int64_t>>> heap;
  heap.emplace(0, source);
  while (!heap.empty()) {
    const auto [closest_distance, closest_vertex] = heap.top();
    if (closest_vertex == destination) {
      return closest_distance;
    }
    heap.pop();
    if (closest_distance < kInfinity) {
      if (distance[closest_vertex] == closest_distance) {
        for (const auto& [source, adjacent, edge_length, interval] : graph[closest_vertex]) {
          const int64_t time = ((closest_distance + interval - 1) / interval) * interval + edge_length;
          if (distance[adjacent] > time) {
            distance[adjacent] = time;
            heap.emplace(distance[adjacent], adjacent);
          }
        }
      }
    } else {
      break;
    }
  }
  return -1;
}
