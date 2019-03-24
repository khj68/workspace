#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int len;
int cnt;
int arr[26][26];
bool visit[26][26];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
vector<int> v;



void dfs(int x, int y){
  visit[x][y] = true;

  for(int i=0; i<4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];

    if(nx == 0 || ny == 0 || nx == n+1 || ny == n+1) continue;
    if(arr[nx][ny] == 0) continue;
    if(visit[nx][ny] == true) continue;

    dfs(nx, ny);
    len++;
  }

}

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%1d", &arr[i][j]);
    }
  }

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      len = 1;
      if(arr[i][j] == 1 && visit[i][j] == false) {
        dfs(i,j);
        v.push_back(len);
        cnt++;
      }
    }
  }
  sort(v.begin(), v.end());

  printf("%d\n", cnt);
  for(auto a : v){
    printf("%d\n", a);
  }
  
}