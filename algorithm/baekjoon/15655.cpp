#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
int arr[8];
int ans[8];
bool visit[8];

void bt(int i, int count){
  if(count == m){
    for(int j=0; j<m; j++){
      printf("%d ", ans[j]);
    }
    printf("\n");
    return;
  }

  for(int j=0; j<n; j++){
    if(visit[j] == true) continue;
    if(i>0 && arr[j] == ans[i-1]) continue;
    if(arr[j] < ans[i-1]) continue;
    ans[i] = arr[j];
    bt(i+1, count+1);
    // visit[j] = false;
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);

  bt(0, 0);

}