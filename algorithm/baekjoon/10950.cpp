#include <stdio.h>
#include <vector>
using namespace std;

int main(){
  int t;
  vector<int> answer;

  scanf("%d", &t);

  
  for(int i=0; i<t; i++){

    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a+b);
  }

  return 0;
}