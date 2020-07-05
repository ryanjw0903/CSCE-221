#include <iostream>
#include <cstdlib>
#include "Stress_ball.h"
#include "Collection.h"
#include <fstream>
#include <sstream>
using CollectionSB = Collection<Stress_ball, Stress_ball_colors,
        Stress_ball_sizes>;
istream& operator>>(istream& is, CollectionSB& c){
    string word;
    Stress_ball_sizes size;
    Stress_ball_colors color;
    Stress_ball sb;
    while(is >> word){
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
using namespace std;
void test_stress_balls(){
    CollectionSB one;
    CollectionSB two;
    CollectionSB three;
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

    cout << "The number of stress balls for Collection one is " << one.total_items() << endl;
    int num_col = one.total_items(Stress_ball_colors ::red);
    cout << "The number of red stress balls are " << num_col << endl;
    cout << "The number of stress balls for Collection two is " << two.total_items() << endl;
    num_col = two.total_items(Stress_ball_colors ::blue);
    cout << "The number of blue stress balls are " << num_col << endl;
    operator<<(cout, two);
    cout << "Union of the one and two" << endl;
    three = make_union(one,two);
    operator<<(cout,three);
    Stress_ball test;
    test = Stress_ball(Stress_ball_colors ::green, Stress_ball_sizes ::medium);
    int num_three = 0;
    for(int i = 0; i<three.total_items();i++){
        if(three[i] == test){
            num_three++;
        }
    }

    cout << "There is " << num_three << " green mediums in collection three" <<endl;
    cout << "There is a total of " << three.total_items() <<" Stress balls" << endl;
    swap(one,two);
    cout << "The new set one" << endl;
    operator<<(cout,one);
    cout << "The new set two" << endl;
    operator<<(cout,two);
}

/*
    cout << "Default constructor test:\n";
    Stress_ball arr_test[5];
    for(int i = 0; i < 5; i++){
        arr_test[i] = Stress_ball();
    }

    cout << "\nTwo arg constructor test:\n";
    Stress_ball test2(Stress_ball_colors::red, Stress_ball_sizes::small);
    cout << test2 << endl;

    Stress_ball test3(Stress_ball_colors::green, Stress_ball_sizes::large);
    cout << test3 << endl;

    cout << "\nCompare stress balls:\n";
    for (int i = 0; i < 5; i++) {
        if (arr_test[i] == test2) {
            cout << "arr_test[" << i << "] equal test2\n";
        } else if (arr_test[i] == test3) {
            cout << "arr_test[" << i << "] equal test3\n";
        } else {
            cout << "arr_test[" << i << "] not equal test2 nor test3\n";
        }
    }

}
 */
