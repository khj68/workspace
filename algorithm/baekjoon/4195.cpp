#include <iostream>
#include <cstdio>
#include <map>
#include <string>

#define swap(a,b){int t=a; a=b; b=t;}

using namespace std;

typedef pair<int, int> pii;

int node;

pii parent[200001];
int level[200001];

int finds(int u){
  if (u==parent[u].first) return u;

  return parent[u].first = finds(parent[u].first);
}

void merge(int u, int v){
  u = finds(u);
  v = finds(v);

  if(u==v) {
    printf("%d\n", parent[v].second);
    return;
  }

  if(level[u] > level[v]) swap(u, v);

  parent[u].first = v;

  if(level[u] == level[v]) ++level[v];

  parent[v].second += parent[u].second;
  printf("%d\n", parent[v].second);
}


int main() {
  int n, t , cnt = 1;
  char name1[21], name2[21];

  scanf("%d", &n);

  while(n--){
    map<string, int> m;
    scanf("%d", &t);

    for(int i=0; i<t; i++){
      scanf("%s %s", name1, name2);

      if(m[name1] == 0){
        parent[cnt].first = cnt;
        parent[cnt].second = 1;
        level[cnt] = 1;
        m[name1] = cnt++;
      }

      if(m[name2] == 0){
        parent[cnt].first = cnt;
        parent[cnt].second = 1;
        level[cnt] = 1;
        m[name2] = cnt++;
      }

      merge(m[name1], m[name2]);
    }
  }


  return 0;
}