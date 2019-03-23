#include <iostream>
#include <vector>
using namespace std;

int main(){

  vector<double> numbers;

  cout <<"Size: "<< numbers.size() << endl;

  int capacity = numbers.capacity();
  cout << "Capacity: " << capacity << endl;

  for(int i=0; i<10000; i++){
    if(numbers.capacity() != capacity){
      capacity = numbers.capacity();
      cout << "Capacity: " << capacity << endl;
    }
    
    numbers.push_back(i);
    
  }
  cout <<"Size: "<< numbers.size() << endl;

  numbers.reserve(1000000);
  cout << numbers[555] << endl;
  cout <<"Size: "<< numbers.size() << endl;
  cout << "Capacity: " << capacity << endl;

  return 0;
}