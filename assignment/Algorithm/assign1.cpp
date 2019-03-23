#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

typedef struct{
  int y,x;
  int depth;
}coordinate;


int main(int argc, char** argv){
  FILE* fpIn = fopen(argv[1], "r");
  FILE* fpOut = fopen(argv[2], "w");
  int n;
  vector<pair<int,int>> moves = {{-1,-2}, {-2,-1}, {-2,1}, {-1,2}, {1,-2}, {2,-1}, {2,1}, {1,2}};

  queue<coordinate> q; 
  coordinate start, end;
  bool haveAnswer = false;
  
  fscanf(fpIn, "%d", &n);

  bool** visit = new bool*[n];
  for(int i=0; i<n; i++){
    visit[i] = new bool[n];
    memset(visit[i], 0, sizeof(bool)*n);
  }

  fscanf(fpIn, "%d %d", &start.y, &start.x);
  fscanf(fpIn, "%d %d", &end.y, &end.x);

  

  q.push({start.y, start.x, 0});
  visit[start.y][start.x] = true;

  while(!q.empty()){
    auto tmp = q.front(); q.pop();
    if(tmp.y == end.y && tmp.x == end.x){
      fprintf(fpOut, "%d", tmp.depth);
      haveAnswer = true;
      break;
    }
  
    for(int i=0; i<8; i++){
      int ny = tmp.y + moves[i].first;
      int nx = tmp.x + moves[i].second;

      if(nx<0 || ny<0 || nx==n || ny==n) continue;
      if(visit[ny][nx] == true) continue;

      visit[ny][nx] = true;
      q.push({ny, nx, tmp.depth+1});
    }
  }

  if(!haveAnswer) fprintf(fpOut, "-1");

  



  for(int i=0; i<n; i++){
    delete [] visit[i];
  }
  delete [] visit;
  fclose(fpIn);
  fclose(fpOut);
}