#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

struct Edge {
  int source, destination, id;
  Edge (int source_ = 0, int destination_ = 0, int id_ = 0)
    : source(source_), destination(destination_), id(id_) { }
};

void dfs(const std::vector<std::vector<std::pair<int, int>>>& graph,
         std::vector<int>& visited, const std::vector<Edge>& edges,
         std::vector<int>& answers, int vertex) {
  visited[vertex] = true;
  for (const auto& [adjacent, edge_id] : graph[vertex]) {
    if (answers[edge_id] == -1) {
      if (edges[edge_id].source == vertex) {
        answers[edge_id] = 1;
      } else {
        answers[edge_id] = 0;
      }
      if (!visited[adjacent]) {
        dfs(graph, visited, edges, answers, adjacent);
      }
    }
  }
}


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int vertex_count, edge_count;
  std::cin >> vertex_count >> edge_count;

  std::vector<Edge> edges(edge_count);
  for (int edge_id = 0; edge_id < edge_count; ++edge_id) {
    auto& edge = edges[edge_id];
    std::cin >> edge.source >> edge.destination;
    --edge.source, --edge.destination;
    edge.id = edge_id;
  }

  std::vector<int> labels(vertex_count);
  for (auto& label : labels) {
    std::cin >> label;
  }

  std::vector<int> answers(edge_count, -1);

  std::vector<std::vector<std::pair<int, int>>> graph(vertex_count);
  for (int edge_id = 0; edge_id < edge_count; ++edge_id) {
    const auto& edge = edges[edge_id];
    if (labels[edge.source] > labels[edge.destination]) {
      answers[edge.id] = 1;
    } else if (labels[edge.source] < labels[edge.destination]) {
      answers[edge.id] = 0;
    } else {
      graph[edge.source].emplace_back(edge.destination, edge.id);
      graph[edge.destination].emplace_back(edge.source, edge.id);
    }
  }

  std::vector<int> visited(vertex_count);
  for (int vertex = 0; vertex < vertex_count; ++vertex) {
    if (!visited[vertex]) {
      dfs(graph, visited, edges, answers, vertex);
    }
  }

  for (auto answer : answers) {
    // assert(answer != -1);
    if (answer) {
      std::cout << "->" << "\n";
    } else {
      std::cout << "<-" << "\n";
    }
  }

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
