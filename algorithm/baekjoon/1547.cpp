#include <cstdio>

using namespace std;

bool ball[51];
int n;
int a, b;
int ans;

int main(){
  scanf("%d", &n);
  ans = 1;
  for(int i=0; i<n; i++){
    scanf("%d %d", &a, &b);
    if(a == ans){
      ans = b;
    }else if(b == ans){
      ans = a;
    }
  }
  printf("%d", ans);
}