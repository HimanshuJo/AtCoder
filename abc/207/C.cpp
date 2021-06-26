#include <bits/stdc++.h>
using namespace std;
// half-open interval
struct Interval {
  int left, right;
  Interval(int left_ = 0, int right_ = 0)
    : left(left_), right(right_) { }
  Interval Intersection(const Interval& other) const {
    return Interval(max(left, other.left), min(right, other.right));
  }
  bool Empty() const {
    return right <= left;
  }
  bool Intersects(const Interval& other) const {
    return !Intersection(other).Empty();
  }
  void Print() const {
    cout << "[" << left << ", " << right << ")\n";
  }
};
struct Event {
  int position, index; bool open;
  Event(int position_ = 0, int index_ = 0, bool open_ = false)
    : position(position_), index(index_), open(open_) { }
  bool operator<(const Event& other) const {
    return make_tuple(position, open, index) \
      < make_tuple(other.position, other.open, other.index);
  }
};
int main() {
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<Interval> intervals(n);
  for (auto& interval : intervals) {
    int t, l, r;
    cin >> t >> l >> r;
    l <<= 1, r <<= 1;
    --t;
    if (t & 2) {
      ++l;
    }
    if (!(t & 1)) {
      ++r;
    }
    interval = Interval(l, r);
  }
  vector<Event> events(n << 1);
  for (int i = 0; i < n; ++i) {
    events[i << 1] = Event(intervals[i].left, i, true);
    events[(i << 1) | 1] = Event(intervals[i].right, i, false);
  }
  sort(events.begin(), events.end());
  int ci = 0, co = 0;
  for (auto event : events) {
    if (event.open) {
      ci += co;
      ++co;
    } else {
      --co;
    }
  }
  cout << ci << "\n";
  return 0;
}