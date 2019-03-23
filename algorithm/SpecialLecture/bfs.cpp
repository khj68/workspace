#include <cstdio>
#include <queue>
#include <tuple>

using namespace std;


int board[502][502] =
  {{1,1,1,0,1,0,0,0,0,0},
   {1,0,0,0,1,0,0,1,1,0},
   {1,1,1,0,1,0,0,1,0,0},
   {1,1,0,0,1,0,0,1,0,0},
   {0,1,1,1,1,1,1,1,0,0},
   {0,0,0,0,0,0,0,1,0,0},
   {0,0,0,0,0,0,0,1,1,1} };

bool visit[502][502];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int main() {
  queue<tuple<int, int, int>> q;

  q.push({0,0,1});
  visit[0][0] = true;
  while(!q.empty()){
    auto temp = q.front();
    q.pop();
    printf("%d %d visit!\n", get<0>(temp)+1, get<1>(temp)+1);
    if(get<0>(temp) == 6 && get<1>(temp) == 9) {
      printf("FINISH!! LENGTH --> %d\n", get<2>(temp));
      break;
    }
    for(int i=0; i<4; i++){
      int nx = get<0>(temp) + dx[i];
      int ny = get<1>(temp) + dy[i];

      if(nx<0 || ny<0 || nx == 10 || ny == 10) continue;
      if(visit[nx][ny] == true || board[nx][ny] == 0) continue;

      q.push({nx, ny, get<2>(temp)+1});
      visit[nx][ny] = true;
    }

  }
}