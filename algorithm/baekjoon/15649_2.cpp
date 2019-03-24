#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int arr[8];
int n,m;
set<vector<int>> s;

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    arr[i] = i+1;
  }
  
  do{
    vector<int> v;
    for(int i=0; i<m; i++){
      v.push_back(arr[i]);
    }
    s.insert(v);
  }while(next_permutation(arr, arr+n));

  for(auto v : s){
    for(auto a : v){
      printf("%d ", a);
    }
    printf("\n");
  }
}