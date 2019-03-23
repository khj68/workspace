#include <iostream>

using namespace std;

class Test {
  private:
  int id;
  string name;

  public:
  Test(): id(0), name(""){

  }

  Test(const Test &other){
    *this = other;
  }

  Test(int id, string name): id(id), name(name){

  }

  void print(){
    cout << id<< ": " << name << endl;
  }

  const Test &operator=(const Test &other){
    
    id = other.id;
    name = other.name;

    return *this;
  }

  friend ostream &operator<<(ostream &out, const Test &test);
};

ostream &operator<<(ostream &out, const Test &test){
  out << test.id<< ": " << test.name;
}

int main(){ 

  Test test1(10, "Mike");
  Test test2(20, "Bob");

  cout << test1 <<endl <<  test2 << endl;

  
  return 0;
}