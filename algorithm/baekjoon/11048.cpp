#include <cstdio>

using namespace std;

int dp[1001][1001];
int arr[1001][1001];
int n,m;
int dx[2]={-1, 0};
int dy[2]={-1, 0};

void check(int x, int y){
  int M = 0;
  for(int i=0; i<2; i++){
    for(int j=0; j<2; j++){
      if(i==1 && j==1) continue;
      int nx = x + dx[i];
      int ny = y + dy[j];

      if(nx==0) continue;
      M = dp[nx][ny] > M ? dp[nx][ny] : M;
    }
  }
  dp[x][y] = M + arr[x][y];
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%d", &arr[i][j]);
      if(i==1) dp[i][j] = arr[i][j];
    }
  }

  


  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      check(i,j);
    }
  }
  // printf("------------\n");
  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=m; j++){
  //     printf("%d ", dp[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("------------\n");
  printf("%d", dp[n][m]);
}
