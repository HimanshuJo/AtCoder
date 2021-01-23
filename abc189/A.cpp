#include <iostream>
#include <string>

int main() {
  std::string slots;
  std::cin >> slots;

  // you can also explicitly compare all pairs:
  // s[0] == s[1] && s[0] == s[2] && s[1] == s[2]
  // but the idea of transitivity is important
  // so it is better to learn how to use it

  if (slots[0] == slots[1] && slots[1] == slots[2]) {
    std::cout << "Won";
  } else {
    std::cout << "Lost";
  }

  return 0;
}
