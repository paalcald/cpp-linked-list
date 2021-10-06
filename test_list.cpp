#include <iostream>
#include "int_linked_list.hpp"
using namespace pab;
int main () {
  List<int> l1;
  l1.push_back(3);
  l1.push_front(1);
  l1.push_front(2);
  l1.push_back(0);
  std::cout << l1 << "\n";
  std::cout << l1.len() << " " << l1[3] << "\n";
  List<int> l2 = l1;
  l1.pop_front();
  std::cout << l1 << "\n";
  std::cout << l2 << "\n";
  l1 = l2;
}
