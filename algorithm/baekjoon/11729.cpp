#include <cstdio>

using namespace std;

int dp[21];
int cnt;
int arr[3][20];

void f(int n, int a, int b, int left){
  if(n==1){
    printf("%d %d\n", a,b);
    cnt++;
  }else{
    f(n-1, a, left, b);
    f(1, a,b, left);
    f(n-1, left, b, a);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  dp[1] = 1;
  for(int i=2; i<=n; i++){
    dp[i] = 2*dp[i-1] + 1;
  }

  printf("%d\n", dp[n]);
  f(n, 1,3,2);
}