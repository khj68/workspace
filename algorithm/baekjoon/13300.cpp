#include <cstdio>
#include <vector>

using namespace std;

int n, room;
int sex, grade;
int arr[6][2];
int ans;

int main(){
  scanf("%d %d", &n, &room);
  for(int i=0; i<n; i++){
    scanf("%d %d", &sex, &grade);
    arr[grade-1][sex]++;
  }

  // printf("-------------\n");
  // for(int i=0; i<6; i++){
  //   for(int j=0; j<2; j++){
  //     printf("%d ", arr[i][j]);
  //   }
  //   printf("\n");
  // }
  // printf("-----------------");
  for(int i=0; i<6; i++){
    for(int j=0; j<2; j++){
      while(arr[i][j] > 0){
        ans++;
        arr[i][j] -= room;
      }
    }
  }
  printf("%d", ans);
}