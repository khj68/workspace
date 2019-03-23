#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {

  string answer = "";
  sort(participant.begin(), participant.end());
  sort(completion.begin(), completion.end());
  for(int i=0; i<participant.size(); i++){
    if(i == participant.size() - 1){
      answer = participant[i];
      break;
    }
    if(participant[i] != completion[i]){
      answer = participant[i];
      break;
    }
  }

  return answer;
}

int main() {
  vector<string> participant;
  vector<string> completion;
  
  participant.push_back("leo");
  participant.push_back("kiki");
  participant.push_back("eden");

  completion.push_back("eden");
  completion.push_back("kiki");

  cout << solution(participant, completion) ;

  return 0;
}