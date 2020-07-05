// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;
template<typename T>
class TemplatedDLList; // class declaration

// doubly linked list node
template<typename T>
struct DLListNode {
  T obj;
  DLListNode<T> *prev, *next;
  DLListNode(T e=T(), DLListNode *p = nullptr, DLListNode *n = nullptr)
    : obj(e), prev(p), next(n) {}
};

// doubly linked list class
template<typename T>
class TemplatedDLList {
private:
  DLListNode<T> header, trailer;
public:
  TemplatedDLList() : header(T()), trailer(T())// default constructor
  { header.next = &trailer; trailer.prev = &header; }
  TemplatedDLList(const TemplatedDLList<T>& dll); // copy constructor
  TemplatedDLList(TemplatedDLList<T>&& dll); // move constructor
  ~TemplatedDLList(); // destructor
  TemplatedDLList& operator=(const TemplatedDLList<T>& dll); // copy assignment operator
  TemplatedDLList& operator=(TemplatedDLList<T>&& dll); // move assignment operator
  // return the pointer to the first node
  DLListNode<T> *first_node() const { return header.next; } 
  // return the pointer to the trailer
  const DLListNode<T> *after_last_node() const { return &trailer; }
  // return if the list is empty
  bool is_empty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insert_first(T obj); // insert to the first node
  T remove_first(); // remove the first node
  void insert_last(T obj); // insert to the last node
  T remove_last(); // remove the last node
  void insert_after(DLListNode<T> &p, T obj);
  void insert_before(DLListNode<T> &p, T obj);
  T remove_after(DLListNode<T> &p);
  T remove_before(DLListNode<T> &p);
  int count(TemplatedDLList<T>& dll);
};

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
    explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
template<typename T>
TemplatedDLList<T>::TemplatedDLList(const TemplatedDLList<T>& dll)
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode<T> * n = dll.first_node();
    while(n!=dll.after_last_node()){
        this->insert_last(n->obj);
        n = n->next;
    }

}

// move constructor
template<typename T>
TemplatedDLList<T>::TemplatedDLList(TemplatedDLList<T>&& dll)
{
    // adjust for empty 
    header = dll.header;
    trailer = dll.trailer;
    dll.header.next = &trailer;
    dll.header.prev = nullptr;
    dll.header.obj = T();
    dll.trailer.prev = &header;
    dll.trailer.next = nullptr;
    dll.trailer.obj = T();
}
// copy assignment operator
template<typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(const TemplatedDLList<T>& dll)
{
    if(this!= &dll){
        DLListNode<T> * prev_node, * node = header.next;
        while(node!=&trailer){
            prev_node = node;
            node = node->next;
            delete prev_node;
        }
        header.next = &trailer;
        trailer.prev = &header;
        DLListNode<T> * n = dll.first_node();
        while(n!=dll.after_last_node()){
            this->insert_last(n->obj);
            n = n->next;
        }
    }
    return *this;
}

// move assignment operator
template<typename T>
TemplatedDLList<T>& TemplatedDLList<T>::operator=(TemplatedDLList<T>&& dll)
{
    if(this!= &dll){
        DLListNode<T> * prev_node, * node = header.next;
        while(node!=&trailer){
            prev_node = node;
            node = node->next;
            delete prev_node;
        }
        header = dll.header;
        trailer = dll.trailer;
        dll.header.next = &trailer;
        dll.header.prev = nullptr;
        dll.header.obj = T();
        dll.trailer.prev = &header;
        dll.trailer.next = nullptr;
        dll.trailer.obj = T();
    }
    return *this;
}
// destructor
template<typename T>
TemplatedDLList<T>::~TemplatedDLList()
{
    DLListNode<T> * prev_node, * node = header.next;
    while(node!=&trailer){
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// insert a new object as the first one
template<typename T>
void TemplatedDLList<T>::insert_first(T obj)
{
    DLListNode<T> * newnode = new DLListNode<T>(obj, &header, header.next);
    header.next->prev = newnode;
    header.next = newnode;
}

// insert a new object as the last one
template<typename T>
void TemplatedDLList<T>::insert_last(T obj)
{
    DLListNode<T> * newnode = new DLListNode<T>(obj, trailer.prev, &trailer);
    trailer.prev->next = newnode;
    trailer.prev = newnode;
}
template<typename T>
// remove the first node from the list
T TemplatedDLList<T>::remove_first()
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    DLListNode<T> * n = header.next;
    n->next->prev = &header;
    header.next = n->next;
    T obj = n->obj;
    delete n;
    return obj;
}

// remove the last node from the list
template<typename T>
T TemplatedDLList<T>::remove_last()
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    DLListNode<T> * n = trailer.prev;
    n->prev->next = &trailer;
    trailer.prev = n->prev;
    T obj = n->obj;
    delete n;
    return obj;
}
template<typename T>
// return the first object (do not remove)
T TemplatedDLList<T>::first() const
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    return header.next->obj;
}
template<typename T>
// return the last object (do not remove)
T TemplatedDLList<T>::last() const
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    return trailer.prev->obj;
}
template<typename T>
// insert a new node after the node p
void TemplatedDLList<T>::insert_after(DLListNode<T> &p, T obj)
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    if(&p == &trailer){
        throw EmptyDLList("can't insert after trailer");
    }
    DLListNode<T> * newnode = new DLListNode<T>(obj,&p,p.next);
    p.next->prev = newnode;
    p.next = newnode;

}

// insert a new node before the node p
template<typename T>
void TemplatedDLList<T>::insert_before(DLListNode<T> &p, T obj)
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    if(&p == &header){
        throw EmptyDLList("can't insert before header");
    }
    DLListNode<T> * newnode = new DLListNode<T>(obj,p.prev,&p);
    p.prev->next = newnode;
    p.prev= newnode;
}
template<typename T>
// remove the node after the node p
T TemplatedDLList<T>::remove_after(DLListNode<T> &p)
{
     if(is_empty()){
        throw EmptyDLList("Empty List");
    }
     if(&p == &trailer || &p == trailer.prev){
        throw EmptyDLList("Cant remove after trailer or trailer prev");
    }
    DLListNode<T> * n = p.next;
    n->next->prev = &p;
    p.next = n->next;
    T obj = n->obj;
    delete n;
    return obj;
}

// remove the node before the node p
template<typename T>
T TemplatedDLList<T>::remove_before(DLListNode<T> &p)
{
     if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    if(&p == &header || &p == header.next){
        throw EmptyDLList("Cant remove before header");
    }
    DLListNode<T> * n = p.prev;
    n->prev->next = &p;
    p.prev = n->prev;
    T obj = n->obj;
    delete n;
    return obj;
}
template<typename T>
int TemplatedDLList<T>::count(TemplatedDLList<T>& dll){
    int num = 0;
    DLListNode<T> * n = dll.first_node();
    if(!dll.is_empty()){
        while(n != dll.after_last_node()){
            num++;
            n =n->next;
        }
    }
    return num;
}

// output operator
template<typename T>
ostream& operator<<(ostream& out, const TemplatedDLList<T>& dll)
{
    DLListNode<T> * n = dll.first_node();
    if(!dll.is_empty()){
        while(n != dll.after_last_node()){
            cout << n->obj << ", ";
            n =n->next;
        }
    }
    return out;
}


#endif
