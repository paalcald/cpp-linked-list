#include <iostream>
#include "int_linked_list.hpp"

void show(List l) {
  while (l != NULL) {
    std::cout << l->data << " ";
    l = l->next;
  }
}

void push(int e, List& l) {
  Node* new_node = new Node;
  new_node->data = e;
  new_node->next = l;
  l = new_node;
}

void append(int e, List& l) {
  Node* new_node = new Node;
  new_node->data = e;
  new_node->next = nullptr;
  Node* current = l;
  if (current == nullptr)
    l = new_node;
  else {
    while (current->next != nullptr)
      current = current->next;
    current->next = new_node;
  }
}

void free(List& l) {
  Node* next = l;
  if (next == nullptr)
    return;
  else {
    while(next->next != nullptr) {
     next = next->next;
      delete l;
      l = next; 
    }
    delete l;
    l = nullptr;
    return;
  }
}

void pop(List& l) {
  if (l == nullptr)
    return;
  else {
    Node * next = l->next;
    delete l;
    l = next;
  }
}

void pop_back(List& l) {
  if (l == nullptr)
    return;
  else {
    Node* current = l;
    Node* last = l;
    while(current->next != nullptr) {
      last = current;
      current = current->next;
    }
    delete current;
    last->next = nullptr;
    return;
  }
}
