//
// Created by ryanj on 1/24/2020.
//
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "Collection.h"
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
    array = new Stress_ball[capacity];
}
template <class Obj, class F1, class F2>
Collection<Obj, F1,F2>:: Collection(const Collection& rhs){
    size = rhs.size;
    capacity = rhs.size;
    array = new Stress_ball[size];
    for(int i = 0; i < size; i++){
            array[i] = rhs.array[i];
    }
}
template <class Obj, class F1, class F2>
Collection& Collection<:: operator=(const Collection & rhs){
    if(this != &rhs){
        size = rhs.size;
        capacity = rhs.size;
        array = new Stress_ball[size];
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
void Collection::resize(){
    Stress_ball* a2;
    if(capacity == 0){
        capacity =1;
    }
    a2 = new Stress_ball[capacity*2];
    for(int i = 0; i < size; i++){
        a2[i] = array[i];
    }
    delete array;
    array = a2;
    capacity*=2;
}
void Collection::insert_item(const Stress_ball &sb) {
    if(size == capacity){
        resize();
    }
    for(int i = size; i > 0; i--){
        array[i] = array[i-1];
    }
    array[0] = sb;
    size ++;
}
bool Collection :: contains(const Stress_ball &sb) const{
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
Stress_ball Collection :: remove_any_item(){
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
void Collection :: remove_this_item(const Stress_ball& sb){
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
void Collection :: make_empty() {
    delete [] array;
    size = 0;
    capacity =0;
    array = nullptr;
}
bool Collection ::is_empty() const {
    if(size == 0){
        return true;
    } else{
        return false;
    }
}
int Collection :: total_items() const{
    return size;
}
int Collection :: total_items(Stress_ball_sizes s) const{
    int num = 0;
    for(int i = 0; i<size; i++){
        if(array[i].get_size() == s){
            num++;
        }
    }
    return num;
}
int Collection :: total_items(Stress_ball_colors t) const{
    int num = 0;
    for(int i = 0; i<size; i++){
        if(array[i].get_color() == t){
            num++;
        }
    }
    return num;
}
void Collection :: print_items() const{
    for (int i = 0; i < size ; ++i) {
        cout << array[i] << endl;
    }
}
Stress_ball& Collection :: operator[](int i){
    return array[i];
}
const Stress_ball& Collection :: operator[](int i) const{
    return array[i];
}
Collection::Collection(Collection&& c){
    size = c.size;
    capacity = c.capacity;
    array = new Stress_ball[size];
    for(int i = 0; i < size; i++){
        array[i] = c.array[i];
    }
    c.size = 0;
    c.capacity = 0;
    delete [] c.array;
    c.array = nullptr;
}
Collection& Collection :: operator=(Collection&& c){
    if(this!=&c){
        size = c.size;
        capacity = c.capacity;
        array = new Stress_ball[size];
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
istream& operator<<(istream& is, Collection& c){
    string word;
    Stress_ball_colors color;
    Stress_ball_sizes size;
    Stress_ball sb;
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
ostream& operator <<(ostream& os, const Collection& c){
    c.print_items();
}
Collection make_union(const Collection& c1, const Collection& c2){
    Collection three;
    for(int j =0;j<c2.total_items();j++){
        three.insert_item(c2[j]);
    }
    for(int i =0;i<c1.total_items();i++){
        three.insert_item(c1[i]);
    }
    return three;
}
void swap(Collection& c1, Collection& c2) {
    Collection temp;
    temp = c1;
    c1 = Collection(c2);
    c2 = Collection(temp);
}
void sort_by_size(Collection& c, Sort_choice sort) {
    Stress_ball temp;
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
    } else if (sort == Sort_choice::insertion_sort) {
        Stress_ball key;
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
        Stress_ball temp;
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
