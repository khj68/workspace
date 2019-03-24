#include <cstdio>
#include <queue>

using namespace std;

int n,m;
int a,b;
int arr[501][501];
bool visit[501];
int ans;

void dfs(int k, int depth){
  for(int i=1; i<=n; i++){

  }
}

int main(){
  queue<int> q;
  scanf("%d", &n);
  scanf("%d", &m);
  for(int i=0; i<m; i++){
    scanf("%d %d", &a, &b);
    arr[a][b] = 1;
    arr[b][a] = 1;
  }

  for(int i=2; i<=n; i++){
    if(arr[1][i] == 1){
      q.push(i);
      visit[i] = true;
      ans++;
    }
  }
  // printf("----------\n");
  // printf("%d \n", q.front());
  // printf("----------\n");
  while(!q.empty()){
    int tmp = q.front();
    q.pop();
    for(int i=2; i<=n; i++){
      if(visit[i] == true) continue;
      if(arr[tmp][i] == 1) {
        ans++;
        visit[i]= true;
      }
    }
  }

  printf("%d", ans);
}