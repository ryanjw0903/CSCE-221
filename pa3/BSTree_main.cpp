
#include <iostream>
#include <fstream>
#include <string>
#include "BSTree.h"
using namespace std;
BSTree read_file(string file_name)
{
  /*
    open the file and use the input operator (operator>>)
    to construct a new tree
  */
    
  BSTree new_tree;
  ifstream infile;
  infile.open(file_name);
  if(!infile){
    cout << "Error not file name" ;
    exit(0);
  } else {
    while(!infile.eof()){
      infile >> new_tree;
    }
  }
  return new_tree;
}
void output(BSTree& x){
  if(x.get_size()>16){
  string outName = "test.txt";
  ofstream outFile;
  outFile.open(outName);
  x.inorder(outFile,x.get_root());
  outFile << endl;
  outFile << "Total number of nodes " << x.get_size() << endl;
  outFile << "Average search cost " << x.get_average_search_time()<<endl;
  } else{
  x.inorder(cout,x.get_root());
  cout << endl;
  cout << "Total number of nodes " << x.get_size() << endl;
  cout << "Average search cost " << x.get_average_search_time()<<endl;
  cout << "Level-by-level" << endl;
  x.print_level_by_level(cout);
  }
}

int main()
{
// application tests for less then 16 and greater then 16
 BSTree j;
 j.insert(5);
 j.insert(3);
 j.insert(9);
 j.insert(7);
 j.insert(10);
 j.insert(11);
 output(j);
 // search test
 if(j.search(7) == nullptr){
   cout << "Did not find" << endl;
 } else{
   cout << "Did find" << endl;
 }
 BSTree a;
 a.insert(5);
 a.insert(3);
 a.insert(4);
 a.insert(7);
 a.insert(10);
 a.insert(11);
 a.insert(23);
 a.insert(13);
 a.insert(17);
 a.insert(22);
 a.insert(25);
 a.insert(27);
 a.insert(30);
 a.insert(34);
 a.insert(31);
 a.insert(45);
 a.insert(41);
 a.insert(37);
 output(a);
// test the copy constructor
BSTree p(j);
p.inorder(cout,p.get_root());
cout << endl;
// test the copy assignment
BSTree q;
q = p;
q.inorder(cout,q.get_root());
cout << endl;
cout << "Test update search times" << endl;
// test update search times
j.update_search_times();
j.inorder(cout,j.get_root());
cout << endl;
  for(int i = 1; i <= 12; i++) {

    string dir= "data-files/"+ to_string(i);
    BSTree l = read_file(dir+"l");
    cout << "average search time linear " << i << " "
	 << l.get_average_search_time() << endl;
    BSTree p = read_file(dir+"p");
    cout << "average search time perfect "<< i << " "
	 << p.get_average_search_time() << endl;
    BSTree r = read_file(dir+"r");
    cout << "average search time random "<< i << " "
	 << r.get_average_search_time() << endl;

    if(i <= 4) {
      cout << "prefect tree " << i << endl << p;
    }

    cout << endl;
  }
  
}

