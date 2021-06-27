#include <algorithm>
#include <iostream>
#include <vector>

template <typename T = int>
std::vector<T> ReadArray(int size = 0, std::istream& in_stream = std::cin);

// copied from leetcode, O(n)
int largestRectangleArea(const std::vector<int>& height) {
  if (height.empty()) {
    return 0;
  }

  const int length = height.size();

  // you can also maintain stack explicitly
  std::vector<int> previous_smaller(length, -1);
  for (int i = 1; i < length; ++i) {
    int p = i - 1;
    while (p >= 0 && height[p] >= height[i]) {
      p = previous_smaller[p];
    }
    previous_smaller[i] = p;
  }

  std::vector<int> next_smaller(length, length);
  for (int i = length - 2; i >= 0; --i) {
    int p = i + 1;
    while (p < length && height[p] >= height[i]) {
      p = next_smaller[p];
    }
    next_smaller[i] = p;
  }

  int max_rectangle_area = 0;
  for (int i = 0; i < length; ++i) {
    max_rectangle_area = std::max(max_rectangle_area,
      height[i] * (next_smaller[i] - previous_smaller[i] - 1));
  }
  return max_rectangle_area;
}

int main() {
  auto a = ReadArray();
  std::cout << largestRectangleArea(a) << "\n";
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
