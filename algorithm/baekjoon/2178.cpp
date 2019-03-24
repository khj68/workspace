#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;

int arr[101][101];
bool visit[101][101];
int n, m;
queue<tuple<int,int,int>> q;
int len=1;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=m; j++){
      scanf("%1d", &arr[i][j]);
    }
  }
  q.push({1,1,1});
  visit[1][1] = true;
  while(!q.empty()){
    auto tmp = q.front(); q.pop();
    if(get<0>(tmp) == n && get<1>(tmp) == m){
      len = get<2>(tmp);
      break;
    }
    for(int i=0; i<4; i++){
      int nx = get<0>(tmp) + dx[i];
      int ny = get<1>(tmp) + dy[i];
      if(nx == 0 || ny == 0 || nx == n+1 || ny == m+1) continue;
      if(visit[nx][ny] == true || arr[nx][ny] == 0) continue;
      visit[nx][ny] = true;
      q.push({nx, ny, get<2>(tmp)+1});
    }
  }
  printf("%d", len);
  
}