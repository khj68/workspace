#include <string>
#include <vector>
#include <queue>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;

struct Song {
  int number;
  int play;
};

struct pred {
  bool operator()(Song a, Song b) {
    if(a.play == b.play) return b.number < a.number;
    return a.play < b.play;
  }
};

bool pred1(pair<string,int> a, pair<string, int> b){
  return a.second > b.second;
}



vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, priority_queue<int, deque<Song>, pred> > temp;
    map<string, int> temp1;

    Song song;
    for(int i=0; i<genres.size(); i++){
      song.number = i;
      song.play = plays[i];
      temp[genres[i]].push(song);
      temp1[genres[i]] += plays[i];
    }

    vector<pair<string, int> > temp2;
    map<string, int>::iterator itemp1;
    for(itemp1 = temp1.begin(); itemp1 != temp1.end(); itemp1++)
      temp2.push_back(make_pair(itemp1->first, itemp1->second));

    sort(temp2.begin(), temp2.end(), pred1);

    for(int i=0; i<temp2.size(); i++){
      if(temp[temp2[i].first].size() == 1){
        answer.push_back(temp[temp2[i].first].top().number);
        temp[temp2[i]].first].pop();
      }else{
        answer.push_back(temp[temp2[i].first].top().number);
        temp[temp2[i].first].pop();
        answer.push_back(temp[temp2[i].first].top().number);
        temp[temp2[i].first].pop();
      }
    }





    return answer;
}