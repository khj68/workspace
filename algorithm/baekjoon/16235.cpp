#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int ground[11][11];
int food[11][11];
vector<int> tree[11][11];
int n, ans;
int num_tree;
int year;
int dx[4] = {1,-1,0};
int dy[4] = {1,-1,0};

void spring(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(tree[i][j].size() == 0) continue;
      sort(tree[i][j].begin(), tree[i][j].end());
      for(int k=0; k<tree[i][j].size(); k++){   
        if(ground[i][j] < tree[i][j][k]) {
          tree[i][j][k] = -tree[i][j][k];
          continue;
        }
        ground[i][j] -= tree[i][j][k];
        tree[i][j][k]++;
      }
    }
  }
}

void summer(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(tree[i][j].size() == 0) continue;
      for(int k=0; k<tree[i][j].size(); k++){   
        if(tree[i][j][k] >= 0) continue;
        ground[i][j] += (-tree[i][j][k])/2;
        tree[i][j].erase(tree[i][j].begin() + k);
        k--;
      }
    }
  }
}

void check(int x, int y){
  for(int k=0; k<tree[x][y].size(); k++){   
    if(tree[x][y][k] % 5 != 0) continue;
    for(int i=0; i<3; i++){
      for(int j=0; j<3; j++){
        if(i==2 && j==2) continue;
        int nx = x+dx[i];
        int ny = y+dy[j];

        if(nx==0 || ny==0 || nx==n+1 || ny==n+1) continue;
        tree[nx][ny].push_back(1);
      }
    }
  }
  
}

void autumn(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(tree[i][j].size() == 0) continue;
        check(i,j);
    }
  }
}

void winter(){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      ground[i][j] += food[i][j];
    }
  }
}

int main(){
  scanf("%d %d %d", &n, &num_tree, &year);

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d", &food[i][j]);
      ground[i][j] = 5;
    }
  }
  int x,y,tree_age;
  for(int i=1; i<=num_tree; i++){
    scanf("%d %d %d", &x, &y, &tree_age);
    tree[x][y].push_back(tree_age);
  }

  for(int i=1; i<=year; i++){
    for(int y=0; y<4; y++){
      switch(y){
        case 0:
          //spring
          spring();
          break;
        case 1:
          //summer
          summer();
          break;
        case 2:
          //autumn
          autumn();
          break;
        case 3:
          //winter
          winter();
          break;
      }
    }
  }
  
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      ans += tree[i][j].size();
    }
  }
  printf("%d", ans);
}