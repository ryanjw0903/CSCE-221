//
// Created by ryanj on 1/31/2020.
//
#include <iostream>
#include <cstdlib>
#include "Stress_ball.h"
#include "Collection.h"
#include <fstream>
#include <sstream>
void test_stress_balls();
void test_jeans();
using namespace std;
int main() {
    int answer;
    cout << "What version to test: stress_ball (=0) or jeans (=1): ";
    cin >> answer;
    if (answer == 0)
        test_stress_balls();
    else if (answer == 1)
        test_jeans();
    else
        cout << "Wrong value: " << answer << endl;
    return 0;
    /* Is all ine stress_ball_test and jeans_test
    srand(time(NULL));
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
            operator<<(s, one);
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
            operator<<(s, two);
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
    /*cout << "The number of stress balls for Collection one is " << one.total_items() << endl;
    int num_col = one.total_items(Stress_ball_colors::red);
    cout << "The number of red stress balls are " << num_col << endl;
    cout << "The number of stress balls for Collection two is " << two.total_items() << endl;
    num_col = two.total_items(Stress_ball_colors::blue);
    cout << "The number of blue stress balls are " << num_col << endl;

    operator<<(cout, two);
    three = make_union(one,two);
    operator<<(cout,three);

    Stress_ball test;
    test = Obj(F1::green, F2::medium);
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
    */
}