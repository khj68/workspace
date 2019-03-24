#include <cstdio>

using namespace std;

int n,m;
int arr[8];

void btrack(int index, int num){
  arr[num] = index+1; 
  if(num == m-1){
    for(int i=0; i<m; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }
  for(int i=index; i<n; i++){
    btrack(i, num+1);
  }
}

int main(){
  scanf("%d %d", &n, &m);

  for(int i=0; i<n; i++){
    btrack(i, 0);
  }
}