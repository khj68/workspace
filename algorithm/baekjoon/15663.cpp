#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n,m;
int arr[8];
int ans[8];
bool visit[8];
set<vector<int>> s;
int tmp;

void bt(int i, int count){
  if(count == m){
    vector<int> v;

    for(int j=0; j<m; j++){
      v.push_back(ans[j]);
    }
    sort(v.begin(), v.end());

    // printf("\n");
    s.insert(v);
    tmp++;

    return;
  }

  for(int j=0; j<n; j++){
    if(visit[j] == true) continue;
    if(arr[j] < ans[i-1]) continue;
    // visit[j] = true;
    ans[i] = arr[j];
    bt(i+1, count+1);
    // visit[j] = false;
  }
}

int main(){
  scanf("%d %d", &n, &m);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n);

  bt(0, 0);

  for(auto &a : s){
    for(auto &b : a){
      printf("%d ", b);
    }
    printf("\n");
  }
}