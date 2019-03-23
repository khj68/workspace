#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;



bool cmp2(string a, string b){
  return a+b > b+a;
}

string solution(vector<int> numbers) {
  string answer = "";
  vector<string> s;
  bool isZero = true;

  // sort(numbers.begin(), numbers.end(), cmp);
  for(int i=0; i<numbers.size(); i++){
    if(numbers[i]!=0) {
      isZero = false;
      break;
    }
  }
  if(isZero == true) {
    return "0";
  }

  for(int i=0; i<numbers.size(); i++){
    s.push_back(to_string(numbers[i]));
    // answer += to_string(numbers[i]);
  }

  sort(s.begin(), s.end(), cmp2);

  for(int i=0; i<numbers.size(); i++){
    // cout << s[i] << endl;
    answer += s[i];
  }

  // cout<< "answer: " << answer;
  
  return answer;
}

int main() {

  vector<int> a = {0,0,0};

  solution(a);



  return 0;
}