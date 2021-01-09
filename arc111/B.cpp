#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

using Graph = std::unordered_map<int, std::vector<int>>;

void dfs(Graph& graph, std::vector<std::vector<int>>& components,
         std::unordered_set<int>& visited, int vertex) {
  visited.insert(vertex);
  components.back().push_back(vertex);
  for (auto adjacent : graph[vertex]) {
    if (!visited.count(adjacent)) {
      dfs(graph, components, visited, adjacent);
    }
  }
}

std::vector<std::vector<int>> FindComponents(Graph& graph) {
  std::vector<std::vector<int>> components;
  std::unordered_set<int> visited;
  for (const auto& [vertex, _] : graph) {
    if (!visited.count(vertex)) {
      components.emplace_back();
      dfs(graph, components, visited, vertex);
    }
  }
  return components;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i] >> b[i];
  }

  Graph graph;
  for (int i = 0; i < n; ++i) {
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }

  const auto components = FindComponents(graph);

  int answer = 0;

  for (const auto& component : components) {
    const int vertex_count = component.size();

    int edge_count = 0;
    for (auto vertex : component) {
      edge_count += graph[vertex].size();
    }
    edge_count >>= 1;

    if (edge_count == vertex_count - 1) {  // tree
      answer += vertex_count - 1;
    } else {  // has cycle
      answer += vertex_count;
    }
  }

  std::cout << answer << "\n";

  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  std::vector<T> array(size);
  for (auto& element : array) {
    std::cin >> element;
  }
  return array;
}
