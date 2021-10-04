#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>

namespace pab {
  template <typename T>
  struct Node {
    T data;
    Node<T>* next;
  };
  
  template <typename T> 
  struct List {
    Node<T>* head;
    
    void show() const;
    
    List& push(T e);
    
    List& append(T e);

    void free();
    
    List& pop();
    
    List& pop_back();
    
  };
}

template <typename T>
void pab::List<T>::show() const {
  Node<T>* current = head;
  while (current != NULL) {
    std::cout << current->data << " ";
    current = current->next;
  }
}
template <typename T>
pab::List<T>& pab::List<T>::push(T e) {
  pab::Node<T>* new_node = new pab::Node<T>;
  new_node->data = e;
  new_node->next = head;
  head = new_node;
  return *this;
}
template <typename T>
pab::List<T>& pab::List<T>::append(T e) {
  pab::Node<T>* new_node = new pab::Node<T>;
  new_node->data = e;
  new_node->next = nullptr;
  Node<T>* current = head;
  if (current == nullptr)
    head = new_node;
  else {
    while (current->next != nullptr)
      current = current->next;
    current->next = new_node;
  }
  return *this;
}
template <typename T>
void pab::List<T>::free() {
  Node<T>* next = head;
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

template <typename T>
pab::List<T>& pab::List<T>::pop() {
  if (head == nullptr)
    return *this;
  else {
    Node<T> * next = head->next;
    delete head;
    head = next;
    return *this;
  }
}

template <typename T>
pab::List<T>& pab::List<T>::pop_back() {
  if (head == nullptr)
    return *this;
  else {
    Node<T>* current = head;
    Node<T>* last = head;
    while(current->next != nullptr) {
      last = current;
      current = current->next;
    }
    delete current;
    last->next = nullptr;
    return *this;
  }
}

#endif //LINKED_LIST_H
