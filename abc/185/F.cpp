#include <iostream>
#include <vector>

class FenwickTree {
  public:
    explicit FenwickTree(int64_t size) : size_(size) {
      data_.resize(size_, 0);
    }

    FenwickTree(std::vector<int64_t> data) : FenwickTree(data.size()) {
      for (int64_t index = 0; index < size_; ++index) {
        Xor(index, data[index]);
      }
    }

    void Xor(int64_t index, int64_t delta) {
      while (index < size_) {
        data_[index] ^= delta;
        index = index | (index + 1);
      }
    }

    inline int64_t RangeXor(int64_t left, int64_t right) const {
      return PrefixXor(right) ^ PrefixXor(left);
    }

  private:
    int64_t size_;
    std::vector<int64_t> data_;

    int64_t PrefixXor(int64_t right) const {
      int64_t prefix_xor = 0;
      while (right >= 0) {
        prefix_xor ^= data_[right];
        right = (right & (right + 1)) - 1;
      }
      return prefix_xor;
    }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int64_t n, q;
  std::cin >> n >> q;
  std::vector<int64_t> a(n);
  for (auto& ai : a) {
    std::cin >> ai;
  }

  FenwickTree fenwick_tree(a);

  while (q --> 0) {
    int64_t t, x, y;
    std::cin >> t >> x >> y;
    if (t == 1) {
      --x;
      fenwick_tree.Xor(x, y);
    } else {  // t == 2
      x -= 2;
      --y;
      std::cout << fenwick_tree.RangeXor(y, x) << "\n";
    }
  }

  return 0;
}
