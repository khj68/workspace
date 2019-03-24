#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int answer;
int arr[101][101];
bool visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y){
  visit[x][y] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx == 0 || ny == 0 || nx == n+1 || ny == n+1) continue;
    if(visit[nx][ny] == true) continue;
    if(arr[nx][ny] == 0) continue;

    dfs(nx, ny);

  }
}


int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  // printf("---------------\n\n");
  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=n; j++){
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  for(int k=0; k<=100; k++){
    int cnt = 0;
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(arr[i][j] <= k) arr[i][j] = 0;
        visit[i][j] = false;
      }
    }

    // printf("---------------\n\n");
    // for(int i=1; i<=n; i++){
    //   for(int j=1; j<=n; j++){
    //     printf("%d ", arr[i][j]);
    //   }
    //   printf("\n");
    // }

    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(visit[i][j] == true) continue;
        if(arr[i][j] == 0) continue;
        dfs(i, j);
        cnt++;
      }
    }
    answer = max(answer , cnt);
    // printf("answer : %d\n", answer);
  }

  printf("%d", answer);
}