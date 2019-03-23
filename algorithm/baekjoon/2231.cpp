#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
  int n;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    int temp = i;
    int sum = i;
    while(temp){
      sum += temp%10;
      temp /= 10;
    }

    if(sum == n) {
      printf("%d", i);
      break;
    }

    if(i == n){
      printf("0");
      break;
    }
  }

  
}