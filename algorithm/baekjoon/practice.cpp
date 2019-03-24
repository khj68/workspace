#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
  // lambda
  // []() {printf("foo");}(); 

  // char s[20];
  // scanf("%s", s);
  // string strs(s);
  // printf("%s\n", strs.c_str());
  // printf("%d\n", strs.size());
  int arr[5] = {5,1,2,4,3};
  sort(arr, arr+5);
  for(int i=0; i<5; i++){
    printf("%d ", arr[i]);
  }
}