#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int arr[13];
int ans[13];

bool visit[13];

void dfs(int x, int count){
  if(count == 6){
    for(int i=0; i<6; i++){
      printf("%d ", ans[i]);
    }
    printf("\n");
    return;
  }

  for(int i=0; i<n; i++){
    if(visit[i] == true) continue;
    if(i>0 && arr[i] < ans[i-1]) continue;
    
    visit[i] = true;
    ans[x] = arr[i];
    dfs(x+1, count+1);
    visit[i] = false;
  }
}

int main(){
  while(1){
    scanf("%d", &n);
    if(n==0) break;

    for(int i=0; i<n; i++){
      scanf("%d", &arr[i]);
    }
    int *check = new int[n];
    for(int i=0; i<n; i++){
      if(i<6) check[i] = 0;
      else check[i] = 1;
    }

    do{
      for(int i=0; i<n; i++){
        if(check[i] == 0) printf("%d ", arr[i]);
      }
      printf("\n");
    }while(next_permutation(check, check+n));

    // dfs(0, 0);
    printf("\n");
    delete []check;
  }

}