#include <cstdio>

using namespace std;

int main(){
  for(int z=1; z<=10; z++){
    int a;
    scanf("%d\n", &a);
    int sum =0;
    int temp1 = 0, temp2 = 0;
    int stack[200] = {0,};
    int ptr = 0;
    int check = 0;
    int ptr2 = 0;
    char st[200] = {0,};
    for(int i=0; i<a; i++){
      char temp = 0;
      temp = getchar();
      if(temp == '('){
        st[ptr2++] = '(';
      }else if(temp == ')'){
        for(int i= ptr2 -1; i>=0; i--){
          if(st[i] == '('){
            ptr2--;
            break;
          }else{
            stack[ptr++] = st[i];
            ptr2--;
          }
        }
      }else if(temp == '*'){
        for(int i= ptr2 - 1; i>=0; i--){
          if(st[i] == '*'){
            stack[ptr++] = '*';
            ptr2--;
          }else break;
        }
        st[ptr2++] = '*';
      }else if(temp == '+'){
        for(int i= ptr2-1; i>=0; i--){
          if(st[i] == '*'){
            stack[ptr++] = '*';
            ptr2--;
          }else if(st[i] == '+'){
            stack[ptr++] = '+';
            ptr2--;
          }else break;
        }
        st[ptr2++] = '+';
      }else{
        stack[ptr++] = temp - 48;
        }
    }
    for(int i= ptr2-1; i>=0; i--){
      stack[ptr++] = st[i];
    }
    int x1 = 0, y1=1;
    int stack2[200] = {0,};
    int ssptr = 0;
    for(int i=0; i<ptr; i++){
      if(stack[i] == '+'){
        int temp = stack2[ssptr -2] + stack2[ssptr -1];
        stack2[ssptr-2] = temp;
        ssptr--;
      }else if(stack[i] == '*'){
        int temp = stack2[ssptr-2] * stack2[ssptr -1];
        stack2[ssptr-2] = temp;
        ssptr--;
      }else
      {
        stack2[ssptr++] = stack[i];
      }
      }
      printf("#%d %d\n", z, stack2[0]);
    }
  }


