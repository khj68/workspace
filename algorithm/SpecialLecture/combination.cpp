#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  
  vector<int> n;

  for(int i=0; i<6; i++){
    n.push_back(i+1);
  }

  vector<int> ind;

  int k=4;

  for(int i=0; i<k; i++){
    ind.push_back(1);
  }

  for(int i=0; i<n.size()-k; i++){
    ind.push_back(0);
  }

  sort(ind.begin(), ind.end());

  do{
    for(int i=0; i<ind.size(); i++){
      if(ind[i] == 1){
        printf("%d ", n[i]);
      }
    }
    printf("\n");
  }while(next_permutation(ind.begin(), ind.end()));

  return 0;
}