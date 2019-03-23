#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a ,string b){
  int i=0;
  while(a[i] == b[i]) i++;
  return a[i] < b[i];
}

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end(), cmp);

    for(int i=0; i<phone_book.size()-1; i++){
      int num = phone_book[i].size();
      if(phone_book[i][0] != phone_book[i+1][0]) continue;
      for(int j=i+1; j < phone_book.size(); j++){
        // if(phone_book[i][0] != phone_book[i][0]) break;

        if(phone_book[j].substr(0, num) == phone_book[i]) return false;
      }
    }

    return true;
}