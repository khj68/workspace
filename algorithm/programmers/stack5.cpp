#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> heights) {
  vector<int> answer;

  for(int i = 0; i<heights.size(); i++){
    bool isAnswer = false;

    for(int j= i-1; j >= 0; j--){
      if(heights[j] > heights[i]){
        answer.push_back(j+1);
        isAnswer = true;
        break;
      }
    }

    if(isAnswer) continue;

    answer.push_back(0);
  }   
    
  return answer;
}

// int main() {

//   vector<int> heights = {3,9,9,3,5,7,2};

//   vector<int> answer = solution(heights);

//   for(auto a: answer){
//     cout << a <<endl;
//   }



//   return 0;
// }