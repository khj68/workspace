#include <cstdio>
#include <vector>

using namespace std;

pair<int, int> egg[9];
int broken[9];

int main(){
  int n, count=0;
  scanf("%d", &n);

  for(int i=1; i<=n; i++){
    int a, b;
    scanf("%d %d", &a, &b);
    egg[i].first = a;
    egg[i].second = b;
  }
  

  for(int i=1; i<=n; i++){
    if(broken[i] == 1) continue;
    int hitNum=i+1, hitWeight = 301;
    for(int j=1; j<=n; j++){
      // 자기 자신이면넘어감
      if(i==j) continue;
      if(broken[j] == 1) continue;
      // 조건들을 만족시킬시 깰 계란으로 선택
      // 1. i 계란 무게보다 j 계란 내구도가 작은가
      // 2. 깨기로 한 계란 보다 무게가 작은가 -> i 계란 살아남을 수 있다.
      // 3. 
      if(egg[j].second <= hitWeight ){
        hitNum = j;
        hitWeight = egg[j].second;
      }
    }
    if(count == n-1) break;
    egg[i].first -= egg[hitNum].second;
    egg[hitNum].first -= egg[i].second;
    printf("broken : ");
    for(int k=1; k<=n; k++){
      printf("%d ", broken[k]);
    }
    printf("\n");
    if(broken[i] == 0 && egg[i].first <= 0) {
      broken[i] = 1;
      count++;
      printf("COUNT : %d\n", count);
      printf("HITNUM : %d\n", hitNum);
      printf("there\n");

    }
    if(hitNum != i && broken[hitNum] == 0 && egg[hitNum].first <= 0){
      broken[hitNum] = 1;
      count++;
      printf("COUNT : %d\n", count);
      printf("HITNUM : %d\n", hitNum);
      printf("here\n");
    }
    
  }
  
  printf("%d", count);

}