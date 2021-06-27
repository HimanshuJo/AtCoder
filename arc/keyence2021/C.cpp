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

const int mod = 998'244'353;

int modpow(int64_t base, int power) {
  int64_t result = 1;
  while (power) {
    if (power & 1) {
      result *= base;
      result %= mod;
    }
    base *= base;
    base %= mod;
    power >>= 1;
  }
  return result;
}

inline void iadd(int& first, int second) {
  first += second;
  if (first >= mod) {
    first -= mod;
  }
}

inline void imul(int& first, int second) {
  first = (first * 1ll * second) % mod; 
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int h, w, k;
  cin >> h >> w >> k;

  vector<int> diagonals(h + w - 1);
  for (int i = 1; i < min(h, w); ++i) {
    diagonals[i - 1] = i;
  }
  for (int i = min(h, w); i < max(h, w); ++i) {
    diagonals[i - 1] = min(h, w);
  }
  for (int i = max(h, w); i < h + w; ++i) {
    diagonals[i - 1] = h + w - i;
  }
  vector<string> board(h, string(w, '.'));
  while (k --> 0) {
    int hi, wi; char ci;
    cin >> hi >> wi >> ci;
    --hi, --wi;
    board[hi][wi] = ci;
    --diagonals[hi + wi];
  }

  for (auto& diagonal : diagonals) {
    if (diagonal) {
      diagonal = modpow(3, diagonal - 1);
    }
  }

  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[0][0] = 1;
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (diagonals[i + j]) {
        imul(dp[i][j], diagonals[i + j]);
      }
      if (board[i][j] == '.') {
        if (i + 1 < h) {
          iadd(dp[i + 1][j], dp[i][j]);  // for X
          iadd(dp[i + 1][j], dp[i][j]);  // for D
        }
        if (j + 1 < w) {
          iadd(dp[i][j + 1], dp[i][j]);  // for X
          iadd(dp[i][j + 1], dp[i][j]);  // for R
        }
      } else {
        if (diagonals[i + j]) {
          imul(dp[i][j], 3);
        }
        if (board[i][j] == 'X') {
          if (i + 1 < h) {
            iadd(dp[i + 1][j], dp[i][j]);  // for X
          }
          if (j + 1 < w) {
            iadd(dp[i][j + 1], dp[i][j]);  // for X
          }
        } else if (board[i][j] == 'R') {
          if (j + 1 < w) {
            iadd(dp[i][j + 1], dp[i][j]);  // for R
          }
        } else {  // board[i][j] == 'D'
          if (i + 1 < h) {
            iadd(dp[i + 1][j], dp[i][j]);  // for D
          }
        }
      }
    }
  }

  // // debug
  // for (auto row : dp) {
  //   for (auto col : row) {
  //     cout << col << " ";
  //   }
  //   cout << "\n";
  // }
  // cout << "\n";

  if (board[h - 1][w - 1] == '.') {
    cout << (3ll * dp[h - 1][w - 1]) % mod << "\n";
  } else {
    cout << dp[h - 1][w - 1] << "\n";
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
