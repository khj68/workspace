#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// typedef struct dice{
//   int onesix;
//   int twofive;
//   int threefour;
// }dice;

// dice d;
int num[7];

int solution(vector<int> &A) {
  int ans = 10000000;
  for(int i=0; i<A.size(); i++){
    // if(A[i] == 1 || A[i] == 6){
    //   d.onesix++;
    // }else if(A[i] == 2 || A[i] == 5){
    //   d.twofive++;
    // }else if(A[i] == 3 || A[i] == 4){
    //   d.threefour++;
    // }
    num[A[i]]++;
  }
  // for(auto a : num){
  //   printf("%d ", a);
  // }
  // printf("\n");

  for(int i=1; i<=6; i++){
    int tmp = 0;
    for(int j=1; j<=6; j++){
      if(j==i) continue;
      if(j==7-i) continue;
      tmp += num[j];
    }
    tmp += 2*num[7-i];
    
    ans = min(ans, tmp);
  }

  return ans;
}

int main(){
  vector<int> A = {1,2,3};
  
  printf("%d", solution(A));

  return 0;
}