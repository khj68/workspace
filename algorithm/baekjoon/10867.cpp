#include <cstdio>
#include <set>

using namespace std;

int main(){
  set<int> s;
  int n;
  scanf("%d", &n);
  int a;

  for(int i=0; i<n; i++){
    scanf("%d", &a);
    s.insert(a);
  }

  for(auto k : s){
    printf("%d\n", k);
  }
}