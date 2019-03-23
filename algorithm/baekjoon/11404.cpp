#include <cstdio>
#include <algorithm>
#define INF 100005

using namespace std;

int arr[101][101];
int city;
int bus;
int start, fin, fee;

void check(int start, int end){
  
  for(int i=1; i<=city; i++){
    if(i==start || i==end) continue;
    if(arr[start][i] == 0 || arr[i][end] == 0) continue;
    
    else arr[start][end] = min(arr[start][end], arr[start][i] + arr[i][end]);
  }
}

int main(){
  scanf("%d", &city);
  scanf("%d", &bus);

  for(int i=1; i<=city; i++){
    for(int j=1; j<=city; j++){
      arr[i][j] = i==j ? 0 : INF;
    }
  }
  
  for(int i=0; i<bus; i++){
    scanf("%d %d %d", &start, &fin, &fee);
    arr[start][fin] = min(arr[start][fin], fee);
  }

  for(int i=1; i<=city; i++){
    for(int j=1; j<=city; j++){
      for(int k=1; k<=city; k++){
        arr[j][k] = min(arr[j][i]+arr[i][k], arr[j][k]);
      }
    }
  }
  

  

  for(int i=1; i<=city; i++){
    for(int j=1; j<=city; j++){
      if(arr[i][j] == INF) printf("0 ");
      else printf("%d ",arr[i][j]);
    }
    printf("\n");
  }
}