#ifndef PABS_LINKED_LIST_H
#define PABS_LINKED_LIST_H

#include <iostream>
#include <stdexcept>

namespace pab
{
    template <typename T>
    struct Node {
	T data;
	Node<T>* next;
    };
    
    template <typename T> 
    class List
    {
    private:
	Node<T>* head;
	
    public:
	List();
	~List();
	List(const List<T> &m);
	List<T> &operator= (const List<T> &m);

	friend std::ostream& operator<< (std::ostream &output,const pab::List<T>& l) {
	    {
		if (l.head == nullptr) {
		    output << "[]";
		} else if (l.head->next == nullptr) {
		    output << "[" << l.head->data << "]";
		} else {
		    output << "[" << l.head->data;
		    for (pab::Node<T>* current = l.head->next;
			 current != nullptr;
			 current = current->next) {
			output << ", " << current->data;
		    }
		    output << "]";
		}
		return output;
	    }
	}

		void push_front(const T& e);
	void push_back(const T& e);
	void insert(int i, const T &m); //todo
	List<T> slice(int first, int last) const; //todo
	List<T> merge(const List<T> &m1);
	T& operator[](int i) const;
	int len(void) const;
	
	void pop_front();
	void pop_back();
	
    };
    template <typename T>
    std::ostream &operator<< (std::ostream &output, const List<T> &l);
	

    template <typename T>
    void truncate(Node<T>*& node);
}

template <typename T>
int pab::List<T>::len(void) const {
    int length = 0;
    for (Node<T>* node = head; node != nullptr; node = node->next) {
	length++;
    }
    return length;
}

template <typename T>
T& pab::List<T>::operator [] (int n) const {
    Node<T>* node = head;
    for (int i = 0; i < n; i++) {
	if (node == nullptr)
	    throw std::invalid_argument ("index out of range.");
	node = node->next;
    }
    if (node == nullptr)
	throw std::invalid_argument ("index out of range.");
    return node->data;
}
    
template <typename T>
void pab::List<T>::pop_front()
{
    if (head == nullptr) {
	throw std::invalid_argument("method pop_front() is undefined for an empty list.");
    } else {
	Node<T>* tmp = head;
	head = head->next;
	delete tmp;
    }
}

template <typename T>
void pab::List<T>::pop_back()
{
    if (head == nullptr) {
	throw std::invalid_argument("method pop_back() is undefined for an empty list.");
    } else {
	if (head->next == nullptr) {
	    delete head;
	    head = nullptr;
	} else {
	    Node<T>* tmp = head;
	    Node<T>* tmp2 = head->next;
	    while (tmp2->next != nullptr) {
		tmp = tmp2;
		tmp2 = tmp2->next;
	    }
	    tmp->next = nullptr;
	    delete tmp2;
	}
    }
}

template <typename T>
pab::List<T>::List() {
     head = nullptr;
}

template <typename T>
pab::List<T>::List(const pab::List<T> &l_i) {
     Node<T>* n_f = new Node<T>;
     head = n_f;
     for (Node<T>* n_i = l_i.head; n_i != nullptr; n_i = n_i->next) {
	  n_f->data = n_i->data;
	  n_i->next == nullptr ?
	       n_f->next = nullptr	      :
	       n_f->next = new Node<T>;
	  n_f = n_f->next;
     }
}

template <typename T>
pab::List<T>& pab::List<T>::operator= (const pab::List<T> &r_list) {
    if (r_list.head == nullptr) {
	truncate(head);
	head = nullptr;
    }
    if (head == nullptr && r_list.head != nullptr) {
	head = new Node<T>;
    }
    Node<T>* old_node = head;
    for (Node<T>* new_node = r_list.head; new_node != nullptr; new_node = new_node->next) {
	old_node->data = new_node->data;
	if (old_node->next == nullptr && new_node->next != nullptr) 
	    old_node->next = new Node<T>;
	else if (new_node->next == nullptr && old_node->next != nullptr) {
	    truncate(old_node->next);
	    old_node->next = nullptr;
	}
	old_node = old_node->next;
    }
    return *this;
} 

template <typename T>
void pab::truncate(Node<T>*& node)
{
  if (node->next == nullptr) {
    delete node;
  } else {
    truncate(node->next);
    delete node;
  }
}

template <typename T>
pab::List<T>::~List() {
    if (head != nullptr)
	truncate(head);
}

template <typename T>
void pab::List<T>::push_front(const T& e)
{
  pab::Node<T>* new_node = new pab::Node<T>;
  new_node->data = e;
  new_node->next = head;
  head = new_node;

}

template <typename T>
void pab::List<T>::push_back(const T& e) {
  Node<T>* new_node = new Node<T>;
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
}

#endif //PABS_LINKED_LIST_H
