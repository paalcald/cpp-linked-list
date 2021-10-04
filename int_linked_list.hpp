#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Nodo {
  int data;
  struct Nodo* next;
} Node;

typedef struct Nodo* List;

void show(List l);

void push(int e, List& l);

void append(int e, List& l);

void free(List& l);

void pop(List& l);

void pop_back(List& l);

#endif //LINKED_LIST_H
