#include <cstdio>
#include <algorithm>

using namespace std;

int arr[21];
int len=20000000;
int sum;
int n, top;


void getTop(int i, int nsum){
  if(i == n+2) return;
  if(nsum >= top){
    len = min(len, nsum);
  }
  getTop(i+1, nsum+arr[i]);
  getTop(i+1, nsum);
}

int main(){
  int t;
  int cnt=1;
  scanf("%d", &t);

  while(t--){
    len = 22222222;
    sum = 0;
    scanf("%d %d", &n, &top);
    for(int i=1; i<=n; i++){
      scanf("%d", &arr[i]);
    }

    getTop(1, 0);
    printf("#%d %d\n", cnt++, len-top);
  }



}