//
// Created by ryanj on 2/14/2020.
//
#include <iostream>
#include <cstdlib>
#include "Jeans.h"
#include "Collection.h"
#include <fstream>
#include <sstream>
using CollectionJN = Collection<Jeans, Jeans_colors, Jeans_sizes>;
istream& operator>>(istream& is, CollectionJN& c){
    string word;
    Jeans_sizes size;
    Jeans_colors color;
    Jeans sb;
    while(is >> word){
        if(word == "red") {
            color = Jeans_colors::red;
        } else if(word == "blue"){
            color = Jeans_colors::blue;
        }else if(word == "yellow"){
            color = Jeans_colors::yellow;
        }else if(word == "green"){
            color = Jeans_colors::green;
        }else if(word == "small"){
            size = Jeans_sizes :: small;
        }else if(word == "medium"){
            size = Jeans_sizes :: medium;
        }else if(word == "large"){
            size = Jeans_sizes :: large;
        }
    }
    sb = Jeans(color,size);
    c.insert_item(sb);
}
using namespace std;
void test_jeans(){
    CollectionJN one;
    CollectionJN two;
    CollectionJN three;
    string f_name;
    string f_name2;
    cout << "Give file one name" << endl;
    cin >> f_name;
    ifstream fin;
    fin.open(f_name);
    if (!fin) {
        cout << " File could not open " << endl;
        exit;
    } else {
        while (!fin.eof()) {
            string st1;
            getline(fin, st1);
            stringstream s(st1);
            operator>>(s, one);
        }
    }
    cout << "Give file two name" << endl;
    ifstream nif;
    cin >> f_name2;
    nif.open(f_name2);
    if (!nif) {
        cout << " File could not open " << endl;
        exit;
    } else {
        while (!nif.eof()) {
            string st1;
            getline(nif, st1);
            stringstream s(st1);
            operator>>(s, two);
        }
    }
    cout << "Input sort name " << endl;
    cout << "1 = bubble / 2 = insertion / 3 = selection" << endl;
    int num;
    cin >> num;
    switch (num) {
        case 1:
            sort_by_size(one, Sort_choice::bubble_sort);
            sort_by_size(two, Sort_choice::bubble_sort);
        case 2:
            sort_by_size(one, Sort_choice::insertion_sort);
            sort_by_size(two, Sort_choice::insertion_sort);
        case 3:
            sort_by_size(one, Sort_choice::selection_sort);
            sort_by_size(two, Sort_choice::selection_sort);
        default:
            break;
    }
    operator<<(cout, one);

    cout << "The number of Jeans for Collection one is " << one.total_items() << endl;
    int num_col = one.total_items(Jeans_colors ::green);
    cout << "The number of green jeans are " << num_col << endl;
    cout << "The number of Jeans for Collection two is " << two.total_items() << endl;
    num_col = two.total_items(Jeans_colors::yellow);
    cout << "The number of yellow jeans are " << num_col << endl;
    operator<<(cout, two);
    three = make_union(one,two);
    cout << "Union of the one and two" << endl;
    operator<<(cout,three);
    Jeans test;
    test = Jeans(Jeans_colors ::green, Jeans_sizes ::medium);
    int num_three = 0;
    for(int i = 0; i<three.total_items();i++){
        if(three[i] == test){
            num_three++;
        }
    }

    cout << "There is " << num_three << " green mediums in collection three" <<endl;
    cout << "There is a total of " << three.total_items() <<"Jeans" << endl;
    swap(one,two);
    cout << "The new set one" << endl;
    operator<<(cout,one);
    cout << "The new set two" << endl;
    operator<<(cout,two);
}