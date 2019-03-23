#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
  vector<int> answer;

  for(int i=0; i< commands.size(); i++){
    vector<int> temp = array;
    
    // cout << commands[i][0] << " " << commands[i][1] << endl;
    partial_sort(temp.begin()+commands[i][0]-1, temp.begin() + commands[i][1]-1,temp.begin() + commands[i][1]);
    answer.push_back(temp[commands[i][0]-1 + commands[i][2]-1]);


    for(auto a : temp){
      // cout << a <<" ";
    }
  }
  
  return answer;
}

// int main(){

//   vector<int> a = {1,5,2,6,3,7,4};
//   vector< vector<int> > b = {{2,5,3}, {4,4,1}, {1,7,3}};

//   vector<int> c = solution(a,b);

//   for(auto i : c){
//     cout <<i << endl;
//   }

//   return 0;
// }