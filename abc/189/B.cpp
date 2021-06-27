#include <iostream>

int main() {
  int glasses_count, limit;
  std::cin >> glasses_count >> limit;

  // you can also use long doubles and check with precision 1e-3
  // but it is always better not to use floating point numbers

  const int percents_limit = limit * 100;
  int drunk_percents = 0;
  bool drunk = false;

  // you can also subtract from percents_limit instead of adding to drunk_percents
  // but I prefer not to change the input if possible (apart from sorting queries)

  for (int glass = 0; glass < glasses_count && !drunk; ++glass) {
    int volume, percent;
    std::cin >> volume >> percent;

    drunk_percents += volume * percent;

    if (drunk_percents > percents_limit) {
      drunk = true;
      std::cout << glass + 1 << "\n";

      // you can also return 0 here to avoid extra boolean variable 'drunk'
      // but I think that multiple return statements make code difficult to read
    }
  }

  if (!drunk) {
    std::cout << -1 << "\n";
  }

  return 0;
}
