#include <cstdio>
#include <vector>

using namespace std;

vector<int> allPrime2(int n){
  vector<int> ret;
  vector<bool> state(n+1, true);
  state[1] = false;
  for(int i=2; i<=n; i++) {
    if(!state[i]) continue;
    for(int j=i*i; j<=n; j+=i) state[j] = false;
  }
  for(int i=1; i <= n; i++){
    if(state[i]) ret.push_back(i);
  }
  return ret;
}


int main(){
  vector<int> answer = allPrime2(1000);

  for(auto itr = answer.begin(); itr != answer.end(); itr++){
    printf("%d ", *itr);
  }

  
}