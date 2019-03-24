#include <cstdio>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int q[10000];
int n;
int a;
char command[7];
int hd = 0, tl =0;

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%s", command);
    if(!strncmp(command, "pu", 2)){
      //push
      scanf("%d", &a);
      q[tl++] = a;
    }else if(command[0] == 'p'){
      //pop
      if(hd == tl) printf("-1\n");
      else printf("%d\n", q[hd++]);
    }else if(command[0] == 's'){
      //size
      printf("%d\n", tl - hd);
    }else if(command[0] == 'e'){
      //empty
      if(hd == tl) printf("1\n");
      else printf("0\n");
    }else if(command[0] == 'f'){
      //front
      if(hd == tl) printf("-1\n");
      else printf("%d\n", q[hd]);
    }else if(command[0] == 'b'){
      //back
      if(hd == tl) printf("-1\n");
      else printf("%d\n", q[tl-1]);
    }
  }  
}