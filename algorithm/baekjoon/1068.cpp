#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> child_vec;
int n, root;
int answer, del_node;

void how_many_leaf(int now_node){
  if(del_node == now_node) return;
  int ch_size = child_vec[now_node].size();
  switch(ch_size){
    case 0:
      answer++; return;
      break;
    case 1:
      if(child_vec[now_node][0] == del_node){
        answer++; break;
      }
    default :
      for(int ch_idx = 0; ch_idx < ch_size; ch_idx++)
        how_many_leaf(child_vec[now_node][ch_idx]);
      break;
  }
}

int main(){
  scanf("%d", &n);
  child_vec.resize(n);

  for(int in_idx=0; in_idx<n; in_idx++){
    int parent;
    scanf("%d", &parent);
    if(parent != -1) child_vec[parent].push_back(in_idx);
    else root = in_idx;
  }

  scanf("%d", &del_node);
  how_many_leaf(root);
  printf("%d", answer);
  return 0;
}