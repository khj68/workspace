#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int d[10001];
int cards[1001];
int M;

int main(){
  scanf("%d", &n);
  for(int i=1; i<=n; i++){
    scanf("%d", &cards[i]);
  }
  d[0] = cards[0] = 0;
  for(int i=1; i<=n; i++){
    for(int j=1; j<=i; j++){
      d[i] = max(d[i], d[i-j] + cards[j]);
    }
  }

  printf("%d", d[n]);
}