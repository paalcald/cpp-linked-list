#include <iostream>
#include "int_linked_list.hpp"

int main () {
  Node* l1 = nullptr;
  append(3, l1);
  push(1, l1);
  push(2, l1);
  append(0, l1);
  show(l1);
  printf("\n");
  pop_back(l1);
  show(l1);
  printf("\n");
  free(l1);
  printf("%i", l1 == nullptr);
}
