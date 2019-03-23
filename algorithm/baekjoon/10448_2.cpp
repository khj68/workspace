#include <cstdio>

int tri[50];
int arr[5000];
int t, n;

using namespace std;

int main(){
  scanf("%d", &t);
  for(int i=0; i<50; i++){
    tri[i] = (i+1)*(i+2)/2;
  }
  // for(int i=0; i<50; i++){
  //   printf("%d ", tri[i]);
  // }

  for(int i=0; i<50; i++){
    for(int j=0; j<50; j++){
      for(int k=0; k<50; k++){
        arr[tri[i]+tri[j]+tri[k]] = 1;
      }
    }
  }
  while(t--){
    scanf("%d", &n);
    printf("%d\n", arr[n]);
  }
  
}