#include <cstdio>
#include <algorithm>

using namespace std;

int r=0,g=0,b=0;
int n;
char arr[101][101];
bool visit[101][101];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


void dfs(int x, int y, char color){
  visit[x][y] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx == 0 || ny == 0 || nx == n+1 || ny == n+1) continue;
    if(visit[nx][ny] == true) continue;
    if(arr[nx][ny] != color) continue;

    dfs(nx, ny, color);
  }
}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      char temp = getchar();
      while(temp == '\n') temp = getchar();
      arr[i][j] = temp;
    }
  }

  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=n; j++){
  //     printf("%c", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(visit[i][j] == true) continue;

      if(arr[i][j] == 'R'){
        dfs(i, j, arr[i][j]);
        r++;
      }else if(arr[i][j] == 'G'){
        dfs(i, j, arr[i][j]);
        g++;
      }else if(arr[i][j] == 'B'){
        dfs(i, j, arr[i][j]);
        b++;
      }
    }
  }
  // printf("R : %d G : %d B : %d\n", r, g, b);
  printf("%d ", r+g+b);

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(arr[i][j] == 'G') arr[i][j] = 'R';
      visit[i][j] = false;
    }
  }

  r = 0; g = 0;

  // for(int i=1; i<=n; i++){
  //   for(int j=1; j<=n; j++){
  //     printf("%c", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(visit[i][j] == true) continue;
      if(arr[i][j] == 'B') continue;

      if(arr[i][j] == 'R'){
        dfs(i, j, arr[i][j]);
        r++;
      }
    }
  }
  // printf("R : %d G : %d B : %d\n", r, g, b);

  printf("%d", r+b);

}