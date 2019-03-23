#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
  vector<int> answer;

  for(int i=0; i<prices.size(); i++){
    int count =1;
    for(int j=i+1; j<prices.size(); j++){
      // cout<< "j is " << j << endl;
      if(prices[j] < prices[i]){
        answer.push_back(count);
        count++;
        break;
      }

      if(j == prices.size()-1) answer.push_back(count);
      count++;
    }
  }
  answer.push_back(0);


  return answer;
}

// int main() {
//   vector<int> a = {498, 501, 470, 489};

//   vector<int> b = solution(a);

//   for(auto i : b){
//     cout<< i <<endl;
//   }


//   return 0;
// }