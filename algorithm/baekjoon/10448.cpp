#include <cstdio>
#include <algorithm>

using namespace std;

int t;
int n;
int triangle[101];
int ans;

void test(int k, int sum, int cnt, int index){
  if(sum > k) return;
  if(index > 44) return;
  if(cnt == 3){
    if(sum == k) ans = 1;
    return;
  }
  // printf("%d %d %d %d\n", k, sum, cnt, index);
  test(k, sum + triangle[index], cnt+1, index+1);
  test(k, sum + triangle[index], cnt+1, index);
  test(k, sum, cnt, index+1);
}

int equation(int i){
  return i*(i+1)/2;
}

int main(){
  scanf("%d", &t);

  for(int i=1; i<=50; i++){
    triangle[i] = equation(i);
  }

  // for(int i=1; i<=50; i++){
  //   printf("%d ", triangle[i]);
  // }
  
  for(int i=0; i<t; i++){
    ans = 0;
    scanf("%d", &n);
    test(n, 0, 0, 1);
    printf("%d\n", ans);
  }


}