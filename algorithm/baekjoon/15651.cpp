#include <cstdio>
#include <vector>

using namespace std;

int arr[8];
vector<int> v;
int n,m;

void bt(int i){
  if(v.size() == m){
    for(auto &a : v){
      printf("%d ",a);
    }
    v.pop_back();
    printf("\n");
    return;
  }
  for(int j=1; j<=n; j++){
    v.push_back(j);
    bt(j);
  }
    v.pop_back();

}

int main(){
  scanf("%d %d", &n, &m);
  // for(int i=1; i<=n; i++){
    bt(1);
  // }
}