#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <string>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

template <typename T>
void PrintArray(const std::vector<T>& array, std::ostream& out_stream = std::cout,
                bool size = false, char element_separator = ' ', char end = '\n');

template <typename T> 
using Counter = std::unordered_map<T, int>;

template <typename Iterator>
using ValueType = typename std::iterator_traits<Iterator>::value_type;

template <class InputIt>
Counter<ValueType<InputIt>> BuildCounter(InputIt first, InputIt last);

template <typename T>
using IndexedValue = std::pair<int, T>;

template <class InputIt>
std::vector<IndexedValue<ValueType<InputIt>>> Enumerate(InputIt first, InputIt last);

class DSU {
  public:
    explicit DSU(int size);
    int Find(int vertex) const;
    void Union(int first, int second);

  private:
    mutable std::vector<int> parent_;
    std::vector<int> rank_;
};

string invert(string s) {
  for (auto& ch : s) {
    if (ch == 'A') {
      ch = 'B';
    } else {  // ch == 'B'
      ch = 'A';
    }
  }
  return s;
}

vector<string> solve(int n) {
  if (n == 1) {
    return {"AB"};
  } else {
    auto p = solve(n - 1);
    vector<string> r = {string(1 << (n - 1), 'A') + string(1 << (n - 1), 'B')};
    for (auto pi : p) {
      r.push_back(pi);
      r.back() += pi;
      r.push_back(pi);
      r.back() += invert(pi);
    }
    return r;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int n;
  cin >> n;

  cout << (1 << n) - 1 << "\n";

  auto vs = solve(n);
  for (auto vsi : vs) {
    cout << vsi << "\n";
  }
  cout << "\n";

  return 0;
}

template <typename T>
std::vector<T> ReadArray(int size, std::istream& in_stream) {
  if (!size) {
    in_stream >> size;
  }
  std::vector<T> array(size);
  for (auto& element : array) {
    in_stream >> element;
  }
  return array;
}

template <typename T>
void PrintArray(const std::vector<T>& array, std::ostream& out_stream,
                bool size, char element_separator, char end) {
  if (size) {
    out_stream << array.size() << end;
  }
  for (const auto& element : array) {
    out_stream << element << element_separator;
  }
  out_stream << end;
}

template <class InputIt>
Counter<ValueType<InputIt>> BuildCounter(InputIt first, InputIt last) {
  Counter<ValueType<InputIt>> counter;
  for (auto it = first; it != last; ++it) {
    ++counter[*it];
  }
  return counter;
}

template <class InputIt>
std::vector<IndexedValue<ValueType<InputIt>>> Enumerate(InputIt first, InputIt last) {
  std::vector<IndexedValue<ValueType<InputIt>>> pairs;
  for (auto it = first; it != last; ++it) {
    pairs.emplace_back(pairs.size(), *it);
  }
  return pairs;
}

DSU::DSU(int size) {
  rank_.resize(size);
  parent_.resize(size);
  std::iota(parent_.begin(), parent_.end(), 0);
}

int DSU::Find(int vertex) const {
  return (vertex == parent_[vertex]) ? vertex : (parent_[vertex] = Find(parent_[vertex]));
}

void DSU::Union(int first, int second) {
  first = Find(first), second = Find(second);
  if (first != second) {
    if (rank_[first] < rank_[second]) {
      std::swap(first, second);
    }
    parent_[second] = first;
    if (rank_[first] == rank_[second]){
      ++rank_[first];
    }
  }
}
