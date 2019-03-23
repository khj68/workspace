#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100001];
int n;
int ans;
long long sumArr[100001];

long long max(long long a, long long b){
  if(a>b) return a;
  return b;
}

void check(int i, int sum, int len){
  if(i == n+1){
    if(len == 0) return;
    ans = max(ans, sum);
  }

  check(i+1, sum+arr[i], len+1);
  check(i+1, sum, len);
}

int main(){
  long long tmp;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &arr[i]);
  }

  sumArr[0] = arr[0];
  tmp = arr[0];
  for(int i=1; i<n; i++){
    sumArr[i] = max(sumArr[i-1] + arr[i], arr[i]);
    tmp = max(sumArr[i], tmp);
  }

  printf("%d", tmp);
}