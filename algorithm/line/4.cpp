#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;
pii arr[1000000];

int main(){
  int n;
  int a;
  int ans = 0;
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> a;
    arr[i] = {a, i+1};
  }
  sort(arr, arr+n);
  
  for(int i=n-1; i>0; i--){
    ans = max(arr[i].second - arr[i-1].second, ans);
  }
  cout << ans;

  return 0;
}