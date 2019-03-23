#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int arr[21];
int n, s;
int ans;

void dfs(int cnt, int sum, int len){
  if(cnt == n+1){
    if(sum == s && len != 0){
      ans++;
    }
    return;
  }

  dfs(cnt+1, sum +arr[cnt], len+1);
  dfs(cnt+1, sum, len);
}

int main(){
  scanf("%d %d", &n, &s);
  for(int i=1; i<=n; i++){
    scanf("%d", &arr[i]);
  }

  dfs(1,0,0);

  printf("%d", ans);
}