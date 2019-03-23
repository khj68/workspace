#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
  vector<int> answer;
  
  list<pair<int, int>> q;

  for(int i=0; i<progresses.size(); i++){
    q.push_back({progresses[i], speeds[i]});
  }

  while(!q.empty()){
    int count = 0;
    while(q.front().first < 100){
      for(list<pair<int,int>>::iterator it = q.begin(); it != q.end(); it++){
        it->first += it->second;
        // cout << it->first << "  " << it->second <<endl;
      }

      // cout << q.front().first<<endl;
    }
  
    while(q.front().first >= 100){
      q.pop_front();
      count++;
    }

    
    answer.push_back(count);
  }
    
    
  return answer;
}

// int main(){

//   vector<int> progresses = {93,30,55};
//   vector<int> speeds = {1,30,5};

//   vector<int> answer = solution(progresses, speeds);

//   for(auto a : answer){
//     cout << a << endl;
//   }

//   return 0;
// }