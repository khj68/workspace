#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> vec;

int main() {
  int total_num = 0;
  int weight = 0;
  cin >> total_num;

  double total_length, ant_num;
  int min, max;

  for(int i=0; i< total_num; i++) {
    vec.clear();
    min = -1;
    max = -1;

    cin >> total_length >> ant_num;

    for(int j=0; j<ant_num; j++ ){
      int sub;
      cin >> sub;
      vec.push_back(sub);
    }

    sort(vec.begin(), vec.end());

    for(int j=0; j<vec.size(); j++){
      int sub;
      if((total_length/2) > vec[j]) sub = vec[j];
      else sub = total_length - vec[j];

      if(min == -1) min = sub;
      if(min < sub) min = sub;
    }

    for(int j=0; j<vec.size(); j++){
      int sub;
      if((total_length/2) > vec[j]) sub = total_length-vec[j];
      else sub = vec[j];

      if(max==-1){
        max = sub;
      }
      if(max<sub) max = sub;
    }

    cout<<min <<" "<<max<<endl;
    

  }

  return 0;
}