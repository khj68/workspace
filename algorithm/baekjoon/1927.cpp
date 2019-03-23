#include <cstdio>
#include <queue>

using namespace std;

int main(){
  priority_queue<int,vector<int>,greater<int>> q;
  int n,a;
  int zero=0;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &a);
    if(a==0){
      if(q.size() == 0){
        printf("0\n");
      }else{
        printf("%d\n", q.top());
        q.pop();
      }
    }else{
      q.push(a);
    }
  }

}