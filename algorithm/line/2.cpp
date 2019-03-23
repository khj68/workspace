#include <vector>
#include <queue>
#include <cctype>
#include <iostream>

using namespace std;

int main(){
  string input;
  queue<string> elem;
  queue<char> num;
  cin >> input;

  for(int i=0; i<input.size(); ){
    // cout << input[i] << endl;
    if(isdigit(input[i])){
      num.push(input[i]);
      i++;
    }else{
      // char tempStr[3];
      string tempStr = "";
      // tempStr[0] = input[i];
      tempStr += input[i];
      i++;
      if(!isdigit(input[i]) && islower(input[i])){
        tempStr += input[i];
        i++;
      }
      // cout << "temp : " << tempStr << endl;
      elem.push(tempStr);
    }
  }

  if(elem.size() != num.size()){
    // cout << elem.front();
    cout << "error";
    return 0;
  }
  int k = elem.size();
  for(int i=0; i< k; i++){
    cout << elem.front();
    if(num.front() != '1') cout << num.front();
    elem.pop();
    num.pop();
  }
  



  return 0;
}