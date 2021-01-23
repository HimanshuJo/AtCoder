#include <iostream>
#include <iomanip>
#include <unordered_set>
#include <vector>

int main() {
  int squares_count, moves_count, restart_positions_count;
  std::cin >> squares_count >> moves_count >> restart_positions_count;
  std::unordered_set<int> restart_positions;

  while (restart_positions_count --> 0) {
    int restart_position;
    std::cin >> restart_position;
    restart_positions.insert(restart_position);
  }

  bool possible = true;
  std::vector<long double> moves_to_victory(squares_count + moves_count);
  std::vector<long double> restart_probability(squares_count + moves_count);
  long double average = 0, average_restart = 0;

  for (int position = squares_count - 1; position >= 0; --position) {
    if (restart_positions.count(position)) {
      moves_to_victory[position] = 0;
      restart_probability[position] = 1;
    } else {
      moves_to_victory[position] = average / moves_count + 1;
      restart_probability[position] = average_restart / moves_count;
    }

    average -= moves_to_victory[position + moves_count];
    average += moves_to_victory[position];

    average_restart -= restart_probability[position + moves_count];
    average_restart += restart_probability[position];

    if (average_restart >= moves_count) {
      possible = false;
    }
  }

  if (possible) {
    std::cout << std::fixed << std::setprecision(10) \
      << moves_to_victory[0] / (1 - restart_probability[0]) << "\n";
  } else {
    std::cout << -1 << "\n";
  }

  return 0;
}
