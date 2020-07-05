// sorting items from the heaviest to lightest
// by selecting the heaviest item at each time  

#include <iostream>
#include <vector>

using namespace std;

int comparisons = 0;

ostream& operator<<(ostream& out, vector<int>& v)
{
    for(int i = 0; i<v.size(); i++){
        out << v[i] << ", ";
    }
    return out;
}

void sort_heaviest(vector<int>& v){
    {
       ]

    /*
    int heaviest = v[0];
    for(int i =0; i<v.size();i++){
        for(int j = i+1; j<v.size(); j++){
            if(v[j] > v[i]){
                comparisons++;
                swap(v[j],v[i]);
            }
        }
    }
     */
}

int main()
{
    cout << "//////Test 2 for vector v ///////////////////////////////"<< endl;
    vector<int> v{10,9,8,7,6,5,4,3,2,1};
    cout << "initial vector v:\n";
    operator<<(cout, v);
    cout << endl;
    sort_heaviest(v);
    cout << "# of comparisons to sort v: " << comparisons << endl << endl;
    cout << "vector v after sorting:\n";
    operator<<(cout, v);
    // use comma to separate the vector's elements
    cout << endl;

    cout << "//////Test 2 for vector v1 ///////////////////////////////"<< endl;

    vector<int> v1{1,2,3,4,5,6,7,8,9,10};
    cout << "initial vector v1:\n";
    operator<<(cout, v1);
    // use comma to separate the vector's elements
    cout << endl;
    sort_heaviest(v1);
    cout << "# of comparisons to sort v1: " << comparisons << endl << endl;
    cout << "vector v1 after sorting:\n";
    operator<<(cout, v1);
    // use comma to separate the vector's elements
    cout << endl;
}