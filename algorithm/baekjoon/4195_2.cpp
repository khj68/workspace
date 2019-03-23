#include <cstdio>
#include <map>
#include <string>

#define swap(a, b){int t=a; a=b; b=t;}
using namespace std;

typedef pair<int, int> pii;

pii p[200001];
int level[200001];

int finds(int n){
  if(p[n].first == n) return n;
  return p[n].first = finds(p[n].first);
}

void merge(int a, int b){
  int d1 = finds(a);
  int d2 = finds(b);

  if(d1 == d2) {
    printf("%d\n", p[d1].second);
    return;
  }

  if(level[d1] > level[d2]){
    swap(d1, d2);
  }

  p[d1].first = d2;
  p[d2].second += p[d1].second;
  if(level[d1] == level[d2]){
    level[d2]++;
  }
  printf("%d\n", p[d2].second);
}

int main() {
  int t, cnt=1;
  scanf("%d", &t);
  for(int i=0; i<t; i++){
    int n;
    scanf("%d", &n);

    map<string, int> m;

    for(int j=0; j<n; j++){
      char name1[21];
      char name2[21];
      scanf("%s %s", name1, name2);
      if(m[name1] == 0){
        level[cnt] = 1;
        p[cnt].first = cnt;
        p[cnt].second = 1;
        m[name1] = cnt++;
      }

      if(m[name2] == 0){
        level[cnt] = 1;
        p[cnt].first = cnt;
        p[cnt].second = 1;
        m[name2] = cnt++;
      }
      merge(m[name1], m[name2]);
    }
  }


  return 0;
}