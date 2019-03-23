#include <cstdio>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main(){
  // vector<string> v = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
  // vector<string> ans;
  // for(auto s : v){
  //   char str[100];
  //   strcpy(str, s.c_str());
  //   char* tok = strtok(str, " ");
  //   while(tok != nullptr){
  //     ans.push_back(string(tok));
  //     tok = strtok(NULL, " ");
  //   }
  // }

  // for(auto s: ans){
  //   printf("%s\n", s.c_str());
  // }
  vector<vector<string>> v = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
  for(auto v1 : v){
    for(auto v2 : v1){
      printf("%s ", v2.c_str());
    }
    printf("\n");
  }
}
