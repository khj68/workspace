#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[501][501];
bool visit[501][501];
int col, row;
int cnt, area=0;
int len;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void dfs(int x, int y){
  if(visit[x][y] == true) return;
  // printf("DFS\n");
  visit[x][y] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx==0 || ny==0 || nx==col+1 || ny==row+1) continue;
    if(arr[nx][ny] == 0 || visit[nx][ny] == true) continue;

    dfs(nx, ny);
    len++;
  }
}


int main(){
  scanf("%d %d", &col, &row);
  for(int i=1; i<=col; i++){
    for(int j=1; j<=row; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  for(int i=1; i<=col; i++){
    for(int j=1; j<=row; j++){
      len = 1;
      if(arr[i][j] == 1 && visit[i][j] == false){
        dfs(i,j);
        cnt++;
      }
      area = max(area, len);
    }
  }
  
  if(cnt == 0 ){
    printf("0\n0");
    return 0;
  }
  printf("%d\n%d", cnt, area);


}