#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct{
  int x;
  int y;
}co;

bool cmp(co &a, co &b){
  if(a.y == b.y){
    return a.x < b.x;
  }
  return a.y < b.y;
}

int main(){
  int n;
  vector<co> v;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    int x, y;
    scanf("%d %d", &x, &y);
    co tmp;
    tmp.x=x; tmp.y=y;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end(), cmp);
  for(auto tmp:v){
    printf("%d %d\n", tmp.x, tmp.y);
  }
}