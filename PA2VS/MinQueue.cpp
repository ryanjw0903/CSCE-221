#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "MinQueue.h"

using namespace std;

int main ()
{
  cout << "New queue" << endl;
  LinkedQueue<int> ll;
  for (int i=10; i<=100; i+=10) {
      ll.enqueue(i);
  }
  ll.enqueue(2);
  cout << ll.min() << endl;
  int s = ll.size();
  for(int i = 0; i < s; i++){
      cout << ll.dequeue() << " ";
  }
  return 0;
}
