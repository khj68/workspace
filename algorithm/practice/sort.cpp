#include <iostream>
#include <algorithm>

using namespace std;

class Student {
  public:
  string name;
  int score;
  Student(string name, int score) {
    this->name = name;
    this->score = score;
  }

  bool operator < (Student &student) {
    return this->score < student.score;
  }
};

bool cmp(int a, int b) {
  return a>b;
}


int main() {
  Student students[] = {
    Student("kim", 90),
    Student("Nah", 93),
    Student("Kha", 97),
    Student("Pho", 87),
    Student("Tail", 92)
  };
  
  sort(students, students + 5);

  for(int i=0; i<5; i++ ){
    cout << students[i].name << endl;
  }
  
  return 0;
}