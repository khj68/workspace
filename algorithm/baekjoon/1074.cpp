#include <cstdio>
#include <cmath>

using namespace std;

int n,r,c,ans;

int main(){
  scanf("%d %d %d", &n, &r, &c);
  int x = pow(2, n)/2;
  int y = x;
  while(n-- > 0){
    int temp = pow(2,n) /2;
    int skip = pow(4, n);

    if(r < y && c < x){
      x -= temp;
      y -= temp;
    }else if(r < y && x <= c){
      x += temp;
      y -= temp;
      ans += skip;
    }else if(y <= r && c < x){
      x -= temp;
      y += temp;
      ans += skip*2;
    }else{
      x += temp;
      y += temp;
      ans += skip * 3;
    }
  }
  printf("%d", ans);
}