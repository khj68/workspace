#include <cstdio>
#include <vector>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

vector<tuple<int,int,string>> v;

int main(){
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    char str[101];
    int age;
    scanf("%d %s", &age, str);
    string s(str);
    v.push_back({age,i,s});
  }
  sort(v.begin(), v.end());

  for(auto a:v){
    printf("%d %s\n", get<0>(a), get<2>(a).c_str());
  }
}