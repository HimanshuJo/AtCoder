#include <bits/stdc++.h>
using namespace std;

const int kInfinity = std::numeric_limits<int>::max();

using Edge = pair<int, int>;

using Graph = std::vector<std::vector<Edge>>;

int DijkstraHeap(const Graph& graph, int source);

int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

  int n, m;
  cin >> n >> m;
  Graph graph(n);
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    graph[a].emplace_back(b, c);
  }

  for (int s = 0; s < n; ++s)
    cout << DijkstraHeap(graph, s) << "\n";

  return 0;
}

int DijkstraHeap(const Graph& graph, int source) {
  const int vertex_count = graph.size();
  std::vector<int> distance(vertex_count, kInfinity);
  std::priority_queue<std::pair<int, int>,
                      std::vector<std::pair<int, int>>,
                      std::greater<std::pair<int, int>>> heap;
  heap.emplace(0, source);

  while (!heap.empty()) {
    // extract closest unused vertex in O(log n)
    const auto [closest_distance, closest_vertex] = heap.top();
    heap.pop();

    if (closest_vertex == source && closest_distance) {
      return closest_distance;
    }

    if (closest_distance < kInfinity) {
      if (closest_vertex == source || distance[closest_vertex] == closest_distance) {
        // process all outgoing edges from it
        for (const auto& [adjacent, edge_length] : graph[closest_vertex]) {
          if (distance[adjacent] > closest_distance + edge_length) {
            // std::cout << "Updating distance[" << adjacent << "] from " << distance[adjacent] <<
            //   " to " << closest_distance + edge_length << " via " << closest_vertex << "\n";
            distance[adjacent] = closest_distance + edge_length;
            heap.emplace(distance[adjacent], adjacent);
          }
        }
      }  // else this is a fake pair
    } else {  // no more iterations needed, remaining vertices are unreachable
      break;
    }
  }

  return -1;
}