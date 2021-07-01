#include <algorithm>
#include <iostream>
#include <vector>

class FenwickTree {
  public:
    explicit FenwickTree(int64_t size) : size_(size) {
      data_.resize(size_, 0);
    }

    FenwickTree(std::vector<int64_t> data) : FenwickTree(data.size()) {
      for (int64_t index = 0; index < size_; ++index) {
        Add(index, data[index]);
      }
    }

    int64_t Sum(int64_t right) const {
      int64_t sum = 0;
      while (right >= 0) {
        sum += data_[right];
        right = (right & (right + 1)) - 1;
      }
      return sum;
    }

    void Add(int64_t index, int64_t delta) {
      while (index < size_) {
        data_[index] += delta;
        index = index | (index + 1);
      }
    }

  private:
    int64_t size_;
    std::vector<int64_t> data_;
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int64_t h, w, m;
  std::cin >> h >> w >> m;
  std::vector<std::pair<int64_t, int64_t>> block(m);
  for (auto& [i, j] : block) {
    std::cin >> i >> j;
    --i, --j;
  }

  std::vector<int64_t> row(h, w), col(w, h);
  std::vector<std::vector<int64_t>> row_block(h);
  for (const auto& [i, j] : block) {
    row[i] = std::min(row[i], j);
    col[j] = std::min(col[j], i);
    row_block[i].push_back(j);
  }

  int64_t c = 0;
  for (int64_t j = 0; j < row[0]; ++j) {
    c += col[j];
  }

  // . . .
  // . # .
  // . . #
  // . . .

  // . . . .
  // . . . .
  // . # . #
  // . # . .
  // . # . .

  FenwickTree fenwick_tree(w);
  std::vector<int64_t> used(w);
  for (int64_t j = row[0]; j < w; ++j) {
    fenwick_tree.Add(j, 1);
    used[j] = 1;
  }
  for (int64_t i = 0; i < col[0]; ++i) {
    c += fenwick_tree.Sum(row[i] - 1);
    for (int64_t j : row_block[i]) {
      if (!used[j]) {
        fenwick_tree.Add(j, 1);
        used[j] = 1;
      }
    }
  }
  std::cout << c << "\n";

  return 0;
}
