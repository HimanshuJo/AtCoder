#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct Event {
  int time, index;
  bool start;
  inline bool operator<(const Event& other) const {
    return make_tuple(time, start, index) \
      < make_tuple(other.time, other.start, other.index);
  }
};

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

template <typename T>
void PrintArray(const std::vector<T>& array, std::ostream& out_stream = std::cout,
                bool size = false, char element_separator = ' ', char end = '\n');

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n; int64_t C;
  cin >> n >> C;
  vector<Event> abi(n << 1);
  vector<int> c(n);  // [start, end)
  for (int i = 0; i < n; ++i) {
    cin >> abi[i << 1].time;
    abi[i << 1].index = i;
    abi[i << 1].start = true;

    cin >> abi[(i << 1) | 1].time;
    ++abi[(i << 1) | 1].time;
    abi[(i << 1) | 1].index = i;
    abi[(i << 1) | 1].start = false;

    cin >> c[i];
  }

  sort(abi.begin(), abi.end());

  int day = 0;
  int64_t cost = 0;
  int64_t daily_cost = 0;
  for (const auto& event : abi) {
    cost += min(C, daily_cost) * (event.time - day);
    day = event.time;
    if (event.start) {
      daily_cost += c[event.index];
    } else {
      daily_cost -= c[event.index];
    }
  }

  cout << cost << "\n";

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
