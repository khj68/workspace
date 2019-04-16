#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int num[7];

int solution(vector<int> &A) {
  int ans = 100000000;
  for(int i=0; i<A.size(); i++){
    num[A[i]]++;
  }
  for(auto a : num){
    printf("%d ", a);
  }
  printf("\n");
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
  vector<int> A = {1, 6, 2, 3, 4, 1, 5, 1, 2, 3, 4, 1, 2, 3, 4, 6, 1, 2, 3, 4, 1, 2, 3, 1, 6, 4, 2, 3};
  
  printf("%d", solution(A));

  return 0;
}