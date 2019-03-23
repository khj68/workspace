#include <iostream>
#include <vector>
using namespace std;

int main(){

  int values[] = {1,4,5};

  cout << values[0] <<endl;

  class C {
    public:
    string text;
    int id;
  };

  C c1 = {"Hello", 7};

  cout << c1.text<<endl;


  vector<string> strings;

  strings.push_back("one");
  strings.push_back("two");
  strings.push_back("three");
}