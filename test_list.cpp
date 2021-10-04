#include <iostream>
#include "int_linked_list.hpp"
using namespace pab;
int main () {
  List<int> l1{nullptr};
  l1.append(3);
  l1.push(1);
  l1.push(2);
  l1.append(0);
  l1.show();
  printf("\n");
  l1.pop();
  l1.show();
  printf("\n");
  l1.free();
  printf("%i", l1.head == nullptr);
}
