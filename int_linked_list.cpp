#include <iostream>
#include "int_linked_list.hpp"

void pab::List::show() const {
  Node* current = head;
  while (current != NULL) {
    std::cout << current->data << " ";
    current = current->next;
  }
}

pab::List& pab::List::push(int e) {
  pab::Node* new_node = new pab::Node;
  new_node->data = e;
  new_node->next = head;
  head = new_node;
  return *this;
}

pab::List& pab::List::append(int e) {
  pab::Node* new_node = new pab::Node;
  new_node->data = e;
  new_node->next = nullptr;
  Node* current = head;
  if (current == nullptr)
    head = new_node;
  else {
    while (current->next != nullptr)
      current = current->next;
    current->next = new_node;
  }
  return *this;
}

void pab::List::free() {
  Node* next = head;
  if (next == nullptr)
    return;
  else {
    while(next->next != nullptr) {
     next = next->next;
      delete head;
      head = next; 
    }
    delete head;
    head = nullptr;
    return;
  }
}

pab::List& pab::List::pop() {
  if (head == nullptr)
    return *this;
  else {
    Node * next = head->next;
    delete head;
    head = next;
    return *this;
  }
}

pab::List& pab::List::pop_back() {
  if (head == nullptr)
    return *this;
  else {
    Node* current = head;
    Node* last = head;
    while(current->next != nullptr) {
      last = current;
      current = current->next;
    }
    delete current;
    last->next = nullptr;
    return *this;
  }
}
