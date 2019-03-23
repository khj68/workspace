#include <cstdio>

using namespace std;

int n;
int arr[10001];

int main(){
  scanf("%d", &n);
  int a;
  for(int i=0; i<n; i++){
    scanf("%d", &a);
    arr[a]++;
  }

  for(int i=1; i< 10001; i++){
    if(arr[i] == 0) continue;
    while(arr[i]--){
      printf("%d\n", i);
    }
  }
}