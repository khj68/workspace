#include <stdio.h>

int main(){

  FILE* fp = fopen("dict.txt", "r");
  char c;
  while(1){
    c = fgetc(fp);
    printf("수는 %d\n",c);

    if(c == EOF)break;
  }
  
  fclose(fp);
  return 0;
}