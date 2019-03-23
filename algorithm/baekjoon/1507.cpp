#include <cstdio>
#define INF 10001

int arr[21][21];
bool destroy[21][21];
int n;

using namespace std;

int main(){
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      scanf("%d", &arr[i][j]);
    }
  }

  for(int k=1; k<=n; k++){
    for(int i=1; i<=n; i++){
      for(int j=1; j<=n; j++){
        if(i==j || i==k || k == j) continue;

        if(arr[i][j] == arr[i][k] + arr[k][j]){
          destroy[i][j] = true;
        }else if(arr[i][j] > arr[i][k] + arr[k][j]){
          printf("-1");
          return 0;
        }
      }
    }
  }

  int ret=0;
  for(int i=1; i<=n; i++){
    for(int j=i; j<=n; j++){
      ret += !destroy[i][j] * arr[i][j];
    }
  }

  printf("%d", ret);
}