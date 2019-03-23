#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


bool cmp(int a, int b){
  return a>b;
}

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());

    // for(auto a : citations){
    //   cout << a << endl;
    // }
    
    for(int i=0; i<citations.size(); i++){
      

      
      if(citations.size()-i >= citations[i]) answer = citations.size()-i-1;
    }
    if(citations[0] >= citations.size()) return citations.size();
    return answer;
}

int main() {

  vector<int> citations = {1, 2, 3, 3, 3, 3, 4, 4, 5, 6, 7, 7, 8, 8, 9, 9, 10, 10, 10};

  cout<< endl<<solution(citations) << endl;


  return 0;
}