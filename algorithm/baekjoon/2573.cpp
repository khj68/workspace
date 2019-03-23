#include <cstdio>
#include <algorithm>

using namespace std;

int arr[300][300];
int surround[300][300];
bool visit[300][300];
int col, row, cnt, year=1, part;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void check(int x, int y){
  cnt = 0;
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(arr[nx][ny] <= 0) cnt++;
  }
  surround[x][y] = cnt;
}

void dfs(int x, int y){
  visit[x][y] = true;
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(nx<0 || ny<0 || nx == row || ny == col) continue;
    if(arr[nx][ny] <= 0 )continue;
    if(visit[nx][ny] == true) continue;
    dfs(nx, ny);
  }
}

int main(){
  scanf("%d %d", &row, &col);
  for(int i=0; i<row; i++){
    for(int j=0; j<col; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  // printf("----------\n");
  // for(int i=0; i<row; i++){
  //   for(int j=0; j<col; j++){
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }
  while(1){
    bool zero = true;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(arr[i][j] >0) zero = false;
        check(i, j);
      }
    }
    if(zero){
      printf("0");
      break;
    }

    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        arr[i][j] -= surround[i][j];
        visit[i][j] = false;
      }
    }

    part = 0;
    for(int i=0; i<row; i++){
      for(int j=0; j<col; j++){
        if(visit[i][j] == true) continue;
        if(arr[i][j] <= 0) continue;
        dfs(i,j);
        part++;
      }
    }

    // printf("----------\n");
    // for(int i=0; i<row; i++){
    //   for(int j=0; j<col; j++){
    //     printf("%d ", arr[i][j]);
    //   }
    //   printf("\n");
    // }
    
    if(part >= 2) {
      printf("%d", year);
      break;
    }
    year++;
  }


  
}