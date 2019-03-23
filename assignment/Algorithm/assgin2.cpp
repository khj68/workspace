#include <cstdio>
#include <stack>
#include <vector>
#include <cctype>

using namespace std;


int main(int argc, char** argv){
  FILE* fpIn = fopen(argv[1], "r");
  FILE* fpOut = fopen(argv[2], "w");
  
  stack<char> oper;
  vector<char> pre;
  stack<float> answer;

  char temp;

  while(fscanf(fpIn, "%c", &temp) > 0){
    if(isdigit(temp)){
      pre.push_back(temp);
    }else{
      if(temp == '('){
        oper.push(temp);
      }else if(temp == ')'){
        while(1){
          if(oper.top() == '('){
            oper.pop();
            break;
          }
          pre.push_back(oper.top());
          oper.pop();
        }
      }else if(temp == '+' || temp == '-'){
        if(oper.top() != '(' && !oper.empty()){
          pre.push_back(oper.top());
          oper.pop();
        }
        oper.push(temp);
      }else if(temp == '/' || temp == '*'){
        if(!oper.empty() && (oper.top() == '/' || oper.top() == '*')){
          pre.push_back(oper.top());
          oper.pop();
        }
        oper.push(temp);
      }
    }
  }

  while(!oper.empty()){
    pre.push_back(oper.top());
    oper.pop();
  }

  // for(auto a: pre){
  //   printf("%c", a);
  // }
  // printf("\n");

  for(int i=0; i<pre.size(); i++){
    if(isdigit(pre[i])){
      // printf("%f\n", (float)(pre[i]-'0'));
      answer.push((float)(pre[i]-'0'));
    }else{
      float tmp2 = answer.top(); answer.pop();
      float tmp1 = answer.top(); answer.pop();
      
      switch(pre[i]){
        case '+' :
          answer.push(tmp1+tmp2);
          break;
        case '-' :
          answer.push(tmp1-tmp2);
          break;
        case '*' :
          answer.push(tmp1*tmp2);
          break;
        case '/' :
          answer.push(tmp1/tmp2);
          break;
      }
    }
  }
  // printf("%f, %.2f\n", answer.top(), answer.top());
  fprintf(fpOut, "%.2f", answer.top());
  fclose(fpIn);
  fclose(fpOut);
}