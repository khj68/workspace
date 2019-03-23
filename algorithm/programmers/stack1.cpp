#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
  vector<char> s;
  int answer = 0;
  int now=0;
  for(int i=0; i< arrangement.size(); i++){
    if(arrangement[i] == '(' && arrangement[i+1] == ')') {
      answer += now;
      i+=1;
      continue;
    }

    if(arrangement[i] == '(') now++;
    if(arrangement[i] == ')'){
      now--;
      answer++;
    }
  }
  return answer;
}