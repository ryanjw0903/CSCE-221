#include <stdexcept>
#include "DLList.h"


// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
    explicit EmptyDLList(char const* msg=nullptr): runtime_error(msg) {}
};

// copy constructor
DLList::DLList(const DLList& dll)
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    DLListNode * n = dll.first_node();
    while(n!=dll.after_last_node()){
        this->insert_last(n->obj);
        n = n->next;
    }

}

// move constructor
DLList::DLList(DLList&& dll)
{
    header = dll.header;
    trailer = dll.trailer;
    dll.header.next = nullptr;
    dll.header.prev = nullptr;
    dll.header.obj = 0;
    dll.trailer.prev = nullptr;
    dll.trailer.next = nullptr;
    dll.trailer.obj = 0;
}
// copy assignment operator
DLList& DLList::operator=(const DLList& dll)
{
    if(this!= &dll){
        DLListNode * prev_node, * node = header.next;
        while(node!=&trailer){
            prev_node = node;
            node = node->next;
            delete prev_node;
        }
        header.next = &trailer;
        trailer.prev = &header;
        DLListNode * n = dll.first_node();
        while(n!=dll.after_last_node()){
            this->insert_last(n->obj);
            n = n->next;
        }
    }
    return *this;
}

// move assignment operator
DLList& DLList::operator=(DLList&& dll)
{
    if(this!= &dll){
        DLListNode * prev_node, * node = header.next;
        while(node!=&trailer){
            prev_node = node;
            node = node->next;
            delete prev_node;
        }
        header = dll.header;
        trailer = dll.trailer;
        dll.header.next = nullptr;
        dll.trailer.prev = nullptr;
    }
    return *this;
}
// destructor
DLList::~DLList()
{
    DLListNode * prev_node, * node = header.next;
    while(node!=&trailer){
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// insert a new object as the first one
void DLList::insert_first(int obj)
{
    DLListNode * newnode = new DLListNode(obj, &header, header.next);
    header.next->prev = newnode;
    header.next = newnode;
}

// insert a new object as the last one
void DLList::insert_last(int obj)
{
    DLListNode * newnode = new DLListNode(obj, trailer.prev, &trailer);
    trailer.prev->next = newnode;
    trailer.prev = newnode;
}

// remove the first node from the list
int DLList::remove_first()
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    DLListNode * n = header.next;
    n->next->prev = &header;
    header.next = n->next;
    int obj = n->obj;
    delete n;
    return obj;
}

// remove the last node from the list
int DLList::remove_last()
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    DLListNode * n = trailer.prev;
    n->prev->next = &trailer;
    trailer.prev = n->prev;
    int obj = n->obj;
    delete n;
    return obj;
}

// return the first object (do not remove)
int DLList::first() const
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    return header.next->obj;
}

// return the last object (do not remove)
int DLList::last() const
{
    if(is_empty()){
        throw EmptyDLList("Empty List");
    }
    return trailer.prev->obj;
}

// insert a new node after the node p
void DLList::insert_after(DLListNode &p, int obj)
{
    DLListNode * newnode = new DLListNode(obj,&p,p.next);
    p.next->prev = newnode;
    p.next = newnode;

}

// insert a new node before the node p
void DLList::insert_before(DLListNode &p, int obj)
{
    DLListNode * newnode = new DLListNode(obj,p.prev,&p);
    p.prev->next = newnode;
    p.prev= newnode;
}
// remove the node after the node p
int DLList::remove_after(DLListNode &p)
{
    DLListNode * n = p.next;
    n->next->prev = &p;
    p.next = n->next;
    int obj = n->obj;
    delete n;
    return obj;
}

// remove the node before the node p
int DLList::remove_before(DLListNode &p)
{
    DLListNode * n = p.prev;
    n->prev->next = &p;
    p.prev = n->prev;
    int obj = n->obj;
    delete n;
    return obj;
}

// output operator
ostream& operator<<(ostream& out, const DLList& dll)
{
    DLListNode * n = dll.first_node();
    if(!dll.is_empty()){
        while(n != dll.after_last_node()){
            cout << n->obj << ", ";
            n =n->next;
        }
    }
    cout << endl;
    return out;
}

