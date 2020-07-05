#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;
void func(vector<int> one, vector<int> two){
    vector<int> result;
    int i = 0;
    int j = 0;
    while(i<one.size() && j<two.size()){
        if(one[i] < two[j]){
            i++;
        }
        else if(one[i]>two[j]){
            j++;
        }
        else{
            result.push_back(one[i]);
            i++;
            j++;
        }
    }
    for(int k = 0; k<result.size(); k++){
        cout << result[k] << " ";
    }


}
int fdmax(vector<int> v, int n){
    if(n==1){
        return v[0];
    } else{
        int temp = fdmax(v, n-1);
        if(temp > v[n]){
            return temp;
        }
        return v[n];
    }
    
}
int main(){
    vector<int> one {1,2,14,5,9};
    vector<int> two {2,3,7,8,9,10};
    cout << fdmax(one,one.size());
}