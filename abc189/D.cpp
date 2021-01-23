#include <iostream>
#include <string>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

const std::string kAnd = "AND";
const std::string kOr = "OR";

int main() {
  int operations_count;
  std::cin >> operations_count;
  const auto operations = ReadArray<std::string>(operations_count);

  // dp[i][value] - numer of sequences {x_0, ..., x_i} with y_i = value
  std::vector<std::vector<int64_t>> dp(2,
    std::vector<int64_t>(operations_count + 1, 0));
  dp[false][0] = dp[true][0] = 1;

  for (int i = 0; i < operations_count; ++i) {
    for (bool current_y : {false, true}) {
      for (bool next_x : {false, true}) {
        bool next_y;
        if (operations[i] == kAnd) {
          next_y = current_y && next_x; 
        } else {  // operations[i] == kOr
          next_y = current_y || next_x;
        }
        dp[next_y][i + 1] += dp[current_y][i];
      }
    }
  }

  // this dp can be simplified to O(1) space
  // wath https://www.twitch.tv/anandoza for details

  std::cout << dp[true][operations_count] << "\n";

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
