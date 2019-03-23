#include <cstdio>

using namespace std;

int p[1000001];

int finds(int n){
  if(p[n] == n) return n;
  return p[n] = finds(p[n]); 
}

void merge(int a, int b){
  int d1 = finds(a);
  int d2 = finds(b);

  if(d1 == d2) return;

  p[d2] = d1;

}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  for(int i=0; i<=n; i++){
    p[i] = i;
  }
  
  for(int i=0; i<m; i++){
    int a,b,c;
    scanf("%d %d %d", &a,&b, &c);
    
    
    if(a==0){
      // union
      merge(b, c);
    }else {
      // compare
      int d1 = finds(b);
      int d2 = finds(c);

      if(d1 == d2) {
        printf("YES\n");
      }else{
        printf("NO\n");
      }


    }
  }


  return 0;
}