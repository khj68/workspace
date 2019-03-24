#include <cstdio>
#include <algorithm>

using namespace std;

int arr[9];
int combination[9];
int n,m;


int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    arr[i] = i;
  }
  for(int i=1; i<=m; i++){
    combination[i] = 1;
  }

  do{
    for(int i=1; i<=n; i++){
      if(combination[i] == 1){
        printf("%d ", arr[i]);
      }
    }
    printf("\n");
  }while(prev_permutation(combination+1, combination+1+n));
}