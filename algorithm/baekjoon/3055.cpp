#include <cstdio>
#include <utility>

using namespace std;

char arr[51][51];
bool visit[51][51];
int row, col;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
pair<int, int> goal;

void bDfs(int x, int y, int depth){
  if(x==goal.first && y==goal.second){
    printf("%d", depth);
    return;
  }
  
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    
    if(nx==0 || ny==0 || nx==row+1 || ny==col+1) continue;
    if(visit[nx][ny] == true) continue;
    if(arr[nx][ny] == '*') continue;

    visit[nx][ny] = true;
    bDfs(nx, ny, depth+1);
  }
  
}

void wDfs(int x, int y){
  for(int i=0; i<4; i++){
    int nx = x+dx[i];
    int ny = y+dy[i];
    if(nx==0 || ny==0 || nx==row+1 || ny==col+1) continue;

    arr[nx][ny] = '*';

  }
  
}

int main(){
  scanf("%d %d", &row, &col);
  for(int i=1; i<=row; i++){
    scanf("%s", &arr[i][1]);
  }



  for(int i=1; i<=row; i++){
    for(int j=1; j<=col; j++){
      if(arr[i][j] == 'D'){
        goal.first = i;
        goal.second = j;
      }
    }
  }

}