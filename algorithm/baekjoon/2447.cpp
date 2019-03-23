#include <cstdio>

using namespace std;

class star{
private:
  int n;
public:
  star(int n) : n(n){}

  void callDraw(){
    for(int y=0; y<n; y++){
      for(int x=0; x<n; x++){
        draw(y,x);
      }
      printf("\n");
    }
  }
  void draw(int dy, int dx){
    while(dy!=0){
      if(dy%3 == 1 && dx%3 == 1){
        printf(" ");
        return;
      }
      dy/=3;
      dx/=3;
    }
    printf("*");
  }
};

int main(){
  int n;
  scanf("%d", &n);
  star *s = new star(n);
  s->callDraw();
  delete s;
  return 0;
}