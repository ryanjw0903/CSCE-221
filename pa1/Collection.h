//
// Created by ryanj on 1/24/2020.
//

#ifndef PA1_COLLECTION_H
#define PA1_COLLECTION_H

#include <iostream>
#include <string>
enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};
template <class Obj, class F1, class F2>
class Collection {
private:
    Obj *array;
    int size;
    int capacity;
    void resize ();
public:
    Collection();
    Collection(int s);
    Collection(const Collection&);
    Collection& operator=(const Collection &);
    ~Collection();
    void insert_item(const Obj& sb);
    bool contains(const Obj& sb) const;
    Obj remove_any_item();
    void remove_this_item(const Obj& sb);
    void make_empty();
    bool is_empty() const;
    int total_items() const;
    int total_items(F2 s) const;
    int total_items(F1 t) const;
    void print_items() const;
    Obj& operator[](int i);
    const Obj& operator[](int i) const;
    Collection(Collection&& c);
    Collection& operator=(Collection&& c);
};
template <class Obj, class F1, class F2>
Collection<Obj, F1,F2>::Collection(){
    size = 0;
    capacity = 0;
    array = nullptr;
}
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::Collection(int s){
    capacity = s;
    size = 0;
    array = new Obj[capacity];
}
template <class Obj, class F1, class F2>
Collection<Obj, F1,F2>:: Collection(const Collection& rhs){
    size = rhs.size;
    capacity = rhs.size;
    array = new Obj[size];
    for(int i = 0; i < size; i++){
        array[i] = rhs.array[i];
    }
}
template <class Obj, class F1, class F2>
Collection<Obj,F1,F2>& Collection<Obj,F1,F2>:: operator=(const Collection& rhs){
    if(this != &rhs){
    size = rhs.size;
    capacity = rhs.size;
    array = new Obj[size];
        for(int i = 0; i < size; i++){
        array[i] = rhs.array[i];
        }
    }
    return *this;
}
template <class Obj, class F1, class F2>
Collection<Obj, F1, F2>::~Collection(){
    delete [] array;
}
template <class Obj, class F1, class F2>
void Collection<Obj, F1,F2>::resize(){
    Obj* a2;
    if(capacity == 0){
        capacity =1;
    }
    a2 = new Obj[capacity*2];
    for(int i = 0; i < size; i++){
        a2[i] = array[i];
    }
    delete array;
    array = a2;
    capacity*=2;
}
template <class Obj, class F1, class F2>
void Collection<Obj, F1,F2>::insert_item(const Obj &sb) {
    if(size == capacity){
        resize();
    }
    for(int i = size; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = sb;
    size ++;
}
template <class Obj, class F1, class F2>
bool Collection <Obj, F1,F2> :: contains(const Obj &sb) const{
    bool color = false;
    bool siz = false;
    for(int i =0; i<size;i++){
        if(array[i].get_color() == sb.get_color() && array[i].get_size() == sb.get_size()){
            color = true;
            siz = true;
            break;
        }
    }
    if(color == true && siz == true){
        return true;
    } else{
        return false;
    }

}
template <class Obj, class F1, class F2>
Obj Collection<Obj, F1,F2> :: remove_any_item(){
    if(size !=0){
        int idx = rand()%size;
        for(idx; idx <=size; idx++){
            array[idx] = array[idx+1];
        }
        size --;
    }
    else{
        throw;
    }
}
template <class Obj, class F1, class F2>
void Collection<Obj, F1,F2> :: remove_this_item(const Obj& sb){
    if(size != 0) {
        int idx = 0;
        for (int i = 0; i < size; i++) {
            if (array[i].get_color() == sb.get_color() && array[i].get_size() == sb.get_size()) {
                idx = i;
                break;
            }
        }
        for(idx; idx <= size; idx++) {
            array[idx] = array[idx + 1];
        }
        size--;
    }
    else {
        throw;
    }

}
template <class Obj, class F1, class F2>
void Collection<Obj, F1,F2> :: make_empty() {
    delete [] array;
    size = 0;
    capacity =0;
    array = nullptr;
}
template <class Obj, class F1, class F2>
bool Collection<Obj, F1,F2> ::is_empty() const {
    if(size == 0){
        return true;
    } else{
        return false;
    }
}
template <class Obj, class F1, class F2>
int Collection<Obj, F1,F2> :: total_items() const{
    return size;
}
template <class Obj, class F1, class F2>
int Collection<Obj, F1,F2> :: total_items(F2 s) const{
    int num = 0;
    for(int i = 0; i<size; i++){
        if(array[i].get_size() == s){
            num++;
        }
    }
    return num;
}
template <class Obj, class F1, class F2>
int Collection<Obj, F1,F2> :: total_items(F1 t) const{
    int num = 0;
    for(int i = 0; i<size; i++){
        if(array[i].get_color() == t){
            num++;
        }
    }
    return num;
}
template <class Obj, class F1, class F2>
void Collection<Obj, F1,F2> :: print_items() const{
    for (int i = 0; i < size ; ++i) {
        cout << array[i] << endl;
    }
}
template <class Obj, class F1, class F2>
Obj& Collection<Obj, F1,F2> :: operator[](int i){
    return array[i];
}
template <class Obj, class F1, class F2>
const Obj& Collection <Obj, F1,F2>:: operator[](int i) const{
    return array[i];
}
template <class Obj, class F1, class F2>
Collection<Obj, F1,F2>::Collection(Collection&& c){
    size = c.size;
    capacity = c.capacity;
    array = new Obj[size];
    for(int i = 0; i < size; i++){
        array[i] = c.array[i];
    }
    c.size = 0;
    c.capacity = 0;
    delete [] c.array;
    c.array = nullptr;
}
template <class Obj, class F1, class F2>
Collection<Obj,F1,F2>& Collection<Obj, F1,F2> :: operator=(Collection&& c){
    if(this!=&c){
        size = c.size;
        capacity = c.capacity;
        array = new Obj[size];
        for(int i = 0; i < size; i++){
            array[i] = c.array[i];
        }
        c.size = 0;
        c.capacity = 0;
        delete [] c.array;
        c.array = nullptr;
    }
    return *this;
}
template <class Obj, class F1, class F2>
istream& operator<<(istream& is, Collection<Obj,F1,F2>& c){
    string word;
    F1 color;
    F2 size;
    Obj sb;
    while(is>>word){
        if(word == "red") {
            color = Stress_ball_colors::red;
        } else if(word == "blue"){
            color = Stress_ball_colors::blue;
        }else if(word == "yellow"){
            color = Stress_ball_colors::yellow;
        }else if(word == "green"){
            color = Stress_ball_colors::green;
        }else if(word == "small"){
            size = Stress_ball_sizes :: small;
        }else if(word == "medium"){
            size = Stress_ball_sizes :: medium;
        }else if(word == "large"){
            size = Stress_ball_sizes :: large;
        }
    }
    sb = Stress_ball(color,size);
    c.insert_item(sb);
}
template <class Obj, class F1, class F2>
ostream& operator <<(ostream& os, const Collection<Obj,F1,F2>& c){
    c.print_items();
}
template <class Obj, class F1, class F2>
Collection<Obj,F1,F2> make_union(const Collection<Obj,F1,F2>& c1, const Collection<Obj,F1,F2>& c2){
    Collection<Obj,F1,F2> three;
    for(int j =0;j<c2.total_items();j++){
        three.insert_item(c2[j]);
    }
    for(int i =0;i<c1.total_items();i++){
        three.insert_item(c1[i]);
    }
    return three;
}
template <class Obj, class F1, class F2>
void swap(Collection<Obj,F1,F2>& c1, Collection<Obj,F1,F2>& c2) {
    Collection<Obj,F1,F2> temp;
    temp = c1;
    c1 = Collection<Obj,F1,F2>(c2);
    c2 = Collection<Obj,F1,F2>(temp);
}
template <class Obj, class F1, class F2>
void sort_by_size(Collection<Obj,F1,F2>& c, Sort_choice sort) {
    Obj temp;
        if (sort == Sort_choice::bubble_sort) {
            for (int i = 0; i < c.total_items(); i++) {
                for (int j = i + 1; j < c.total_items(); j++) {
                    if (c[i].get_size() > c[j].get_size()) {
                        temp = c[i];
                        c[i] = c[j];
                        c[j] = temp;
                    }
                 }
            }
        }
        else if (sort == Sort_choice::insertion_sort) {
            Obj key;
            int i, j;
             for (i = 0; i < c.total_items(); i++) {
                key = c[i];
                j = i - 1;
                while (j >= 0 && c[j].get_size() > key.get_size()) {
                    c[j + 1] = c[j];
                    j = j - 1;
                }
                c[j + 1] = key;
            }
        } else if (sort == Sort_choice::selection_sort) {
            int i, j, min_idx;
            Obj temp;
            for (i = 0; i < c.total_items() - 1; i++) {
                min_idx = i;
                for (j = i + 1; j < c.total_items(); j++) {
                    if (c[j].get_size() < c[min_idx].get_size()) {
                        min_idx = j;
                    }
                    temp = c[min_idx];
                    c[min_idx] = c[i];
                    c[i] = temp;
                }
            }
        }
    }
/*
istream& operator<<(istream& is, Collection& c);
ostream& operator <<(ostream& os, const Collection& c);
Collection make_union(const Collection& c1, const Collection& c2);
void swap(Collection& c1, Collection& c2);
enum class Sort_choice {bubble_sort, insertion_sort, selection_sort};
void sort_by_size(Collection& c, Sort_choice sort);
 */
#endif //PA1_COLLECTION_H
