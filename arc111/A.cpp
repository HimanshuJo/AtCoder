#include <iostream>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

int64_t ModularPower(int64_t base, int64_t power, int64_t modulo) {
  int64_t result = 1;
  while (power) {
    if (power & 1) {
      result *= base;
      result %= modulo;
    }
    base *= base;
    base %= modulo;
    power >>= 1;
  }
  return result;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int64_t n, m;
  std::cin >> n >> m;

  std::cout << ModularPower(10, n, m * m) / m << "\n";

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
