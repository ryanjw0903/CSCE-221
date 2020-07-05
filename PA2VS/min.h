template<typename T>
class LinkedQueue {
    private:
         // internal LinkedList object
    public:
         TemplatedDLList<T> ll;
        LinkedQueue() : ll() { } // constructor
        ~LinkedQueue() { ll.~TemplatedDLList(); } // destructor
        bool isEmpty( ) const { return ll.is_empty(); }
        void enqueue(T elem) { ll.insert_last(elem); }
        int dequeue() {return ll.remove_first();}
        int size() {return ll.count(ll);}
        int min();

};
template<typename T>
int LinkedQueue<T>::min(){
    if(isEmpty()){
       cout << "List is empty" << endl;
       return 0;
    };
    DLListNode<T> * r = ll.first_node()->next;
    int weak = ll.first();
    while(r!= ll.after_last_node()){
        int temp = r->obj;
        if(temp < weak){
            weak = temp;
        }
        r = r->next;
    }
    return weak;
}
