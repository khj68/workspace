#include <cstdio>
#include <cmath>
using namespace std;

int col[16];
int n;
int answer;


bool check(int i){
  for(int j=1; j<i; j++){
    if(col[i] == col[j] || abs(col[i]-col[j]) == abs(i-j)){
      return false;
    }
  }
  return true;
}

void nQueen(int i){
  if(i == n+1){
    answer += 1;
  }else{
    for(int j=1; j<= n; j++){
      col[i] = j;
      if(check(i)){
        nQueen(i+1);
      }
    }
  }
}


int main(){
  scanf("%d", &n);
  nQueen(1);
  printf("%d", answer);
}