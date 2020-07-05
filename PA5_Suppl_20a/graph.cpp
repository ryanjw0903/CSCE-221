#include "graph.h"
#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
void Graph::buildGraph(ifstream &input){
    string line;
    string num;
    list<int> tlist;
    list<int>* nlist;
    int vertex;
    while(input){
        getline(input , line);
        stringstream ss;
        ss >> num;
        if(num=="-1"){
            break;
        }
        vertex = stoi(num);
        Vertex v(vertex);
        tlist.push_back(vertex);
        while(num != "-1"){
            ss >> num;
            cout << num;
            tlist.push_back(stoi(num));
        }
        nlist = new list<int>(tlist);
        node_list.push_back(v);
        adj_list.push_back(nlist);
        tlist.clear();
    }
}

void Graph :: displayGraph(){
    for(int i = 0; i<adj_list.size();i++){
        list<int>::iterator x;
        for(x=adj_list[i]->begin(); x != adj_list[i]->end() ;x++){
            cout << *x << " ";
        }
        cout << endl;
    }    
}


Graph::~Graph(){

}
// to be implemented
