#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct{
  int c,b,t;
}a;

int conyTime[501];
bool isCatched = false;
int ans=1000;
queue <a> q;
int c,b;


void conyTimeInit(){
  conyTime[1] = 1;
  for(int i=2; i<=501; i++){
    conyTime[i] = conyTime[i-1] + i;
  }
}

int letsCatch(){
  while(!q.empty()){
    auto tmp = q.front();
    q.pop();
    
    if(tmp.c == tmp.b){
      isCatched = true;
      ans = min(ans, tmp.t);
      return ans;
    }
    if(c +conyTime[tmp.t] <= 200000){
      if(tmp.b+1 <= 200000)
        q.push({c+conyTime[tmp.t+1], tmp.b+1, tmp.t+1});
      if(tmp.b*2 <= 200000)
        q.push({c+conyTime[tmp.t+1], tmp.b*2, tmp.t+1});
      if(tmp.b-1 >=0)
        q.push({c+conyTime[tmp.t+1], tmp.b-1, tmp.t+1});
    }
  }
  return -1;
}

int main(){
  int ans;
  cin >> c >> b;
  conyTimeInit();
  
  q.push({c, b, 0});
  cout << letsCatch();
  

  return 0;
}