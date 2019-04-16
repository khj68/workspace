#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// void check(vector<int> &T, int n){
//   for(int i=n; )
// }
  int length_winter = 1;


void check(vector<int> &T, int n, int threshold){
  int size = T.size();
  int newThreshold = threshold;
  bool isNew = false;
  for(int k= n+1; k<size-1; k++){
    if(T[k] > newThreshold){
      isNew = true;
      newThreshold = T[k];
    }
    if(T[k] <= threshold){
      length_winter = k+1;
    }
  }
  if(isNew){
    check(T, length_winter-1, newThreshold);
  }
}

int solution(vector<int> &T) {
  int warmest_winter = T[0];
  int size = T.size();
  for(int i=1; i<size; i++){
    if(T[i] > warmest_winter) {
      int threshold = T[i];
      for(int j=i+1; j<size; j++){
        if(T[j] > threshold) threshold = T[j];
        if(T[j] <= warmest_winter){
          length_winter = j+1;
          check(T, j,threshold);
          break;
        }
      }
      break;
    }
    length_winter++;
  }
  return length_winter;
}

int main(){
  vector<int> t = {-6,-1,1,3,5,1,6,3,-10,4,6,7};
  printf("%d", solution(t));


  return 0;
}

//7, 4, 6, 6, 8, 1, 3, 10, 10