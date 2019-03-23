#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(string &a, string &b){
  if(a.size() != b.size()){
    return a.size() < b.size();
  }

  return a < b;
}

// bool operator<(string &a, string &b){
//   if(a.size() != b.size()){
//     return a.size() < b.size();
//   }

//   return a < b;
// }

int main(){
  int n;
  vector<string> v;
  // set<string> s;
  scanf("%d", &n);
  int tmp = n;


  while(tmp--){
    char str[50];
    scanf("%s", str);
    string a(str);
    // if(s.find(a) != s.end()){
    //   continue;
    // }
    // s.insert(a);
    v.push_back(a);
  }

  sort(v.begin(), v.end(), cmp);
  for(int i=0; i<n; i++){
    if(i!=0 && v[i] == v[i-1]) continue;
    
    printf("%s\n", v[i].c_str());
  }
}