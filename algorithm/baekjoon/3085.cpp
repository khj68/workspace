#include <cstdio>
#include <algorithm>

using namespace std;

char arr[52][52];
int n;
int ans;

void check(){
  for(int i=0; i<n; i++){
    int cnt=1;
    for(int j=1; j<n; j++){
      if(arr[i][j] == arr[i][j-1]){
        cnt++;
      }else{
        ans = max(ans, cnt);
        cnt = 1;
      }
    }
    ans = max(ans, cnt);
  }

  for(int i=0; i<n; i++){
    int cnt=1;
    for(int j=1; j<n; j++){
      if(arr[j][i] == arr[j-1][i]){
        cnt++;
      }else{
        ans = max(ans, cnt);
        cnt=1;
      }
    }
    ans = max(ans, cnt);
  }
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++){
    scanf("%s", arr[i]);
  }
  // printf("-------\n\n");
  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     printf("%c ", arr[i][j]);
  //   }
  //   printf("\n");
  // }

  for(int i=0; i<n; i++){
    for(int j=0; j<n-1; j++){
      char temp = arr[i][j];
      arr[i][j] = arr[i][j+1];
      arr[i][j+1] = temp;
      check();
      temp = arr[i][j+1];
      arr[i][j+1] = arr[i][j];
      arr[i][j] = temp;

      temp = arr[j][i];
      arr[j][i] = arr[j+1][i];
      arr[j+1][i] = temp;
      check();
      temp = arr[j+1][i];
      arr[j+1][i] = arr[j][i];
      arr[j][i] = temp;
    }
  }
  printf("%d",ans);
  
}