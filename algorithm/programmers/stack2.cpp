#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
  int answer = 0;
  priority_queue<int> pq;
  queue<pair<int,int> > q;

  for(int i=0; i<priorities.size(); i++){
    pq.push(priorities[i]);
    q.push({i, priorities[i]});
  }

  while(!q.empty()){
    int index = q.front().first;
    int pri = q.front().second;

    q.pop();
    
    if(pq.top() == pri){
      answer++;
      pq.pop();
      if(index == location){
        return answer;
      }
    }else{
      q.push({index, pri});
    }
  }
 
  return answer;
}