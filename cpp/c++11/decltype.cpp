#include <iostream>
#include <typeinfo>
using namespace std;

int main(){

  int value;

  
  decltype(value) name = 3;

  cout << typeid(value).name() <<endl;

  cout << typeid(name).name() << endl;

  return 0;
}