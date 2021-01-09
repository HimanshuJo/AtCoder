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

struct City {
  int bad_voters, good_voters;
  friend istream& operator>>(istream& in_stream, City& city);
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  auto cities = ReadArray<City>();
  sort(cities.begin(), cities.end(), [] (const City& first, const City& second) -> bool {
    return 2ll * first.bad_voters + first.good_voters > \
      2ll * second.bad_voters + second.good_voters;
  });

  int64_t total_bad = accumulate(cities.begin(), cities.end(), 0ll,
    [] (int64_t accumulator, const City& city) -> int64_t {
      return accumulator + city.bad_voters;
    });
  int64_t total_good = 0;

  int speech_count = 0;
  for (const auto& city : cities) {
    if (total_bad < total_good) {
      break;
    }
    total_bad -= city.bad_voters;
    total_good += city.bad_voters + city.good_voters;
    ++speech_count;
  }
  cout << speech_count;

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

istream& operator>>(istream& in_stream, City& city) {
  in_stream >> city.bad_voters >> city.good_voters;
  return in_stream;
}
