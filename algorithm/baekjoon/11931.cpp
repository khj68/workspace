#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int arr[1000000];
int n;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }
  sort(arr, arr+n/*, greater<int>()*/);
  for(int i=0; i<n; i++){
    printf("%d\n", arr[i]);
  }
}