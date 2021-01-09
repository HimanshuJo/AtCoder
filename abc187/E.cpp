#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

using Edge = pair<int, int>;

using Graph = vector<vector<int>>;

void dfs(int vertex, const Graph& graph, vector<int>& parent) {
  for (auto adjacent : graph[vertex]) {
    if (adjacent && parent[adjacent] == -1) {
      parent[adjacent] = vertex;
      dfs(adjacent, graph, parent);
    }
  }
}

void dfs2(int vertex, const Graph& graph, const vector<int>& parent, 
  const vector<int64_t>& labels, vector<int64_t>& answer, int64_t label = 0) {
  label += labels[vertex];
  answer[vertex] = label;
  for (auto adjacent : graph[vertex]) {
    if (parent[vertex] != adjacent) {
      dfs2(adjacent, graph, parent, labels, answer, label);
    }
  }
  label -= labels[vertex];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int vertex_count;
  cin >> vertex_count;
  Graph graph(vertex_count);
  int edge_count = vertex_count -1;
  const auto edges = ReadArray<Edge>(edge_count);
  for (auto [first, second] : edges) {
    graph[first].push_back(second);
    graph[second].push_back(first);
  }

  vector<int> parent(vertex_count, -1);
  dfs(0, graph, parent);

  vector<int64_t> vertex_labels(vertex_count);

  int query_count;
  cin >> query_count;
  int64_t total_delta = 0;
  while (query_count--) {
    int type, edge_id; int64_t delta;
    cin >> type >> edge_id >> delta;
    --edge_id;
    auto [first, second] = edges[edge_id];
    if (type == 1) {
      if (parent[first] == second) {
        vertex_labels[first] += delta;
      } else {
        vertex_labels[second] -=delta;
        total_delta += delta;
      }
    } else {  // type == 2
      if (parent[second] == first) {
        vertex_labels[second] += delta;
      } else {
        vertex_labels[first] -=delta;
        total_delta += delta;
      }
    }
  }

  vector<int64_t> final_vertex_labels(vertex_count);
  dfs2(0, graph, parent, vertex_labels, final_vertex_labels);
  for (auto final_vertex_label : final_vertex_labels) {
    cout << final_vertex_label + total_delta << "\n";
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
    in_stream >> element.first >> element.second;
    --element.first, --element.second;
  }
  return array;
}
