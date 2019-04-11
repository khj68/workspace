#include <cstdio>
#include <vector>

using namespace std;

int arr[100001];

int solution(vector<int> &A) {
  for(auto a: A){
    // printf("%d\n", a);
    arr[a]++;
  }

  // for(int i=1; i<A.size(); i++){
  //   // printf("%d\n", arr[i]);
  //   if(arr[i] == 0){
  //     printf("%d\n", i);
  //     break;
  //   }
  // }
}


int main(){
  vector<int> a = {1,2,3};
  solution(a);
  int i=1;
  while(true){
    // printf("%d\n", arr[i]);
    if(arr[i] == 0){
      printf("%d\n", i);
      break;
    }
    i++;
  }

  return 0;
}