#include <cstdio>

using namespace std;

int n, k;
int index=-1;
int arr[1000];

int main(){
  scanf("%d %d", &n, &k);
  // int* arr = new int[n];
  int tmp = n;
  for(int i=0; i<n; i++){
    arr[i] = i+1;
  }
  

  printf("<");
  while(tmp--){
    for(int i=0; i<k; i++){
      index = (index+1)%n;
      while(arr[index] == 0){
        index = (index+1)%n;
      }
    }
    if(tmp==0) printf("%d>", arr[index]);
    else printf("%d, ", arr[index]);
    arr[index] = 0;
    
  }  
  return 0;
}