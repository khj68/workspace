#include <cstdio>
#include <algorithm>

using namespace std;

int arr[8][8];
int tempArr[8][8];
bool visit[8][8];
bool wall[8][8];
int n,m;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int ans, real_answer;

void copy(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      tempArr[i][j] = arr[i][j];
    }
  }
}

void spread(int x, int y){
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];

    if(nx<0 || ny<0 || nx==n || ny==m) continue;
    if(visit[nx][ny]==true) continue;
    if(tempArr[nx][ny] == 1 || tempArr[nx][ny] == 2) continue;
    visit[nx][ny] = true;
    tempArr[nx][ny] = 2;
    spread(nx, ny);
  }
}

void check(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(tempArr[i][j] == 0) ans++;
    }
  }
}

void init_visit(){
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      visit[i][j] = false;
    }
  }
}

void print_array(){
  printf("--------------------------------\n");
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      printf("%d ", tempArr[i][j]);
    }
    printf("\n");
  }
  printf("--------------------------------\n");
}

void dfs(int count){
  if(count == 3){
    // print safe zone area
    copy();
    for(int i=0; i<n; i++){
      for(int j=0; j<m; j++){
        if(visit[i][j] == true) continue;
        if(tempArr[i][j] == 1 || tempArr[i][j] == 0) continue;
        visit[i][j] = true;
        spread(i, j);
      }
    }
    check();
    // print_array();
    real_answer = max(real_answer, ans);
    ans = 0;
    init_visit();
    return;
  }

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(wall[i][j] == true) continue;
      if(arr[i][j] == 1 || arr[i][j] == 2) continue;
      wall[i][j] = true;
      arr[i][j] = 1;
      dfs(count+1);
      arr[i][j] = 0;
      wall[i][j] = false;
    }
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      scanf("%d", &arr[i][j]);
    }
  }
  
  dfs(0);
  printf("%d", real_answer);
}