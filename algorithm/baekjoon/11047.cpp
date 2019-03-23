#include <cstdio>
#include <stack>
using namespace std;

int main() {
  stack<int> value;

  int n, k;
  int count=0, sum=0, initK;

  scanf("%d %d", &n, &k);

  initK= k;

  for(int i=0; i<n; i++){
    int temp;
    scanf("%d", &temp);
    value.push(temp);
  }

  // printf("\n");

  // while(!value.empty()) {
  //   printf("%d\n", value.top());
  //   value.pop();
  // }

  while(sum != k) {
    while(value.top() > k) {
      value.pop();
    }
    // printf("top : %d\n", value.top());
    int used = value.top();
    while(k >= value.top()) {
      sum += used;
      k -= used;
      count++;
      // printf("sum : %d, k : %d, count : %d\n", sum, k, count );
      if(sum == initK) break;
    }
    if(sum == initK) break;

  }

  printf("%d", count);




  return 0;
}