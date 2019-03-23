#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
  int answer = 0;
  int bridgeWeight=0;
  queue<int> q;
  queue<int> truckQ;
  for(int i=0; i<truck_weights.size(); i++){
    truckQ.push(truck_weights[i]);
  }

  for(int i=0; i<bridge_length; i++) q.push(0);
  
  while(1){
    // cout << "Bridge weight : " << bridgeWeight << endl;
    int out = q.front();
    q.pop();
    bridgeWeight -= out;

    if(truckQ.front() + bridgeWeight <= weight){
      q.push(truckQ.front());
      bridgeWeight += truckQ.front();
      truckQ.pop();
    }else{
      q.push(0);
    }
    
    answer++;

    if(truckQ.empty()){
      answer += bridge_length;
      break;
    }
  }



    
  return answer;
}


// int main() {
//   vector<int> truck = {10,10,10,10,10,10,10,10,10,10};
//   // cout<< solution(100, 100, truck) <<endl;


//   return 0;
// }