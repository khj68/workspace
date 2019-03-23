#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> m;
    for(int i=0; i<clothes.size(); i++){
      m[clothes[i][1]]++;
    }

    for(auto a = m.begin(); a != m.end(); a++) {
      answer *= (a->second +1);
    }

    
    return answer-1;
}