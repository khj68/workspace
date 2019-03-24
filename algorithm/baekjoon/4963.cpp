#include <cstdio>

using namespace std;

int arr[51][51];
bool visit[51][51];
int w,h;
int ans;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int tx[4] = {1,1,-1,-1};
int ty[4] = {1,-1,1,-1};

void dfs(int x, int y){
  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx==0 || ny==0 || nx==h+1 || ny==w+1) continue;
    if(arr[nx][ny] == 0 || visit[nx][ny] == true) continue;

    visit[nx][ny] = true;
    dfs(nx, ny);
  }
  for(int i=0; i<4; i++){
    int nx = x + tx[i];
    int ny = y + ty[i];
    if(nx==0 || ny==0 || nx==h+1 || ny==w+1) continue;
    if(arr[nx][ny] == 0 || visit[nx][ny] == true) continue;

    visit[nx][ny] = true;
    dfs(nx, ny);
  }
}

int main(){
  while(1){
    ans = 0;
    scanf("%d %d", &w, &h);
    if(w==0 && h==0) break;

    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++){
        scanf("%d", &arr[i][j]);
      }
    }

    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++){
        if(visit[i][j] == true || arr[i][j] == 0) continue;
        dfs(i, j);
        ans++;
      }
    }

    for(int i=1; i<=h; i++){
      for(int j=1; j<=w; j++){
        arr[i][j] = 0;
        visit[i][j] = false;
      }
    }

    printf("%d\n", ans);
  }
}