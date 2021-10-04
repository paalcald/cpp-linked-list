#ifndef LINKED_LIST_H
#define LINKED_LIST_H
namespace pab {
  typedef struct Node {
    int data;
    Node* next;
  } Node;
  
  typedef struct List {
    Node* head;
    
    void show() const;
    
    List& push(int e);
    
    List& append(int e);

    void free();
    
    List& pop();
    
    List& pop_back();
    
  } List;
}

#endif //LINKED_LIST_H
