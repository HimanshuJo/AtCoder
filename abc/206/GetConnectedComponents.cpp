#include <vector>
#include <functional>

using Graph = std::vector<std::vector<int>>;
using ConnectedComponent = std::vector<int>;

std::vector<ConnectedComponent> GetConnectedComponents(const Graph& graph) {
  std::vector<ConnectedComponent> connected_components;

  const int kVertexCount = graph.size();
  std::vector<bool> used(kVertexCount);

  std::function<void(int)> dfs = [&] (int vertex) -> void {
    used[vertex] = true;
    connected_components.back().push_back(vertex);
    for (auto adjacent : graph[vertex]) {
      if (!used[adjacent]) {
        dfs(adjacent);
      }
    }
  };

  for (int vertex = 0; vertex < kVertexCount; ++vertex) {
    if (!used[vertex]) {
      connected_components.emplace_back();
      dfs(vertex);
    }
  }

  return connected_components;
}
