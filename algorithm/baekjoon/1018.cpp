#include <cstdio>
#include <algorithm>

using namespace std;

char arr[52][52];
int col, row;
int ans=1000000000, cnt;

void check(int x, int y, char color){
  char which[2];
  which[0] = color;
  if(color == 'B') which[1] = 'W';
  else which[1] = 'B';
  int index = 0;
  // printf("%c %c %c   -------\n\n",color, which[0], which[1]);
  for(int i=x; i<x+8; i++){
    for(int j=y; j<y+8; j++){
      if(arr[i][j] != which[index]) {
        // printf("arr[i][j] : %c   which : %c   %d %d \n", arr[i][j], which[index], i, j);
        cnt++;
      }
      if(index == 0) index++;
      else index--;
    }
    if(index == 0) index++;
    else index--;
  }
  cnt = min(cnt, 64-cnt);
  ans = min(ans, cnt);
}


int main(){
  scanf("%d %d", &col, &row);

  for(int i=1; i<=col; i++){
    scanf("%s", &arr[i][1]);
  }
  // printf("----------\n\n");
  // for(int i=1; i<=col; i++){
  //   for(int j=1; j<=col; j++){
  //     printf("%c ", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  for(int i=1; i<=col-7; i++){
    for(int j=1; j<=row-7; j++){
      cnt = 0;
      // printf("%c --\n", arr[i][j]);
      check(i, j, arr[i][j]);
      
    }
  }

  printf("%d", ans);
}