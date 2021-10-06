#include <iostream>
#include "int_linked_list.hpp"
using namespace pab;
int main () {
  List<int> l1;
  l1.push_front(9);
  l1.push_front(5);
  l1.push_front(4);
  l1.push_front(0);
  List<int> l2;
  l2.push_front(8);
  l2.push_front(7);
  l2.push_front(4);
  l2.push_front(2);
  List<int> l3 = l1.merge(l2);
  std::cout << l1 << "\n";
  std::cout << l2 << "\n";
  std::cout << l3 << "\n";
}
