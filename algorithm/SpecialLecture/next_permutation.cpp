#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  // vector<int> v(4);
  int v[4];

  for(int i=0; i<4; i++){
    v[i]= i+1;
  }

  do{
    for(int i=0; i<4; i++){
      printf("%d ", v[i]);
    }
    printf("\n");
  }while(next_permutation(v, v+4));
  //(next_permutation(v.begin(), v.end()));

  return 0;
}