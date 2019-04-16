#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef struct tree{
  int x;
  tree* l;
  tree* r;
}tree;

tree* root = nullptr;
int ans = 0;

void preorder(tree* t, set<int> s){
  s.insert(t->x);
  // printf("%d ", t->x);
  ans = max(ans, int(s.size()));
  if(t->l != nullptr) {
    preorder(t->l, s);
  }
  if(t->r != nullptr){
    preorder(t->r, s);
  }
}

int solution(tree * T) {
  set<int> s = {T->x};
  preorder(T, s);
  return ans;
}

void make_tree(){
  tree* a = new tree;
  tree* b = new tree;
  tree* c = new tree;
  tree* d = new tree;
  tree* e = new tree;
  tree* f = new tree;
  tree* g = new tree;
  a->x = 4; a->l = b; a->r = c;
  b->x = 5; b->l = d; b->r = nullptr;
  c->x = 6; c->l = e; c->r = f;
  d->x = 4; d->l = g; d->r = nullptr;
  e->x = 1; e->l = nullptr; e->r = nullptr;
  f->x = 6; f->l = nullptr; f->r = nullptr;
  g->x = 5; g->l = nullptr; g->r = nullptr;
  root = a; 
}

int main(){
  make_tree();
  printf("%d", solution(root));

  return 0;
}