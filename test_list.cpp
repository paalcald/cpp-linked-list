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
  List<int> l3;
  l3.push_front(5);
  l3.push_front(7);
  l3.push_front(0);
  l3.push_front(4);
  l3.push_front(6);
  std::cout << l1 << "\n";
  std::cout << l2 << "\n";
  std::cout << l3 << "\n";
  std::cout << l3.mergesort() << "\n";
}
