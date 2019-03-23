#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool cmp(pair<string, pair<int, int> > a,
         pair<string, pair<int, int> > b) {
           if(a.second.first == b.second.first) {
             return a.second.second > b.second.second;
           } else {
             return a.second.first > b.second.first;
           }
         }


int main() {
  vector< pair< string, pair<int, int> > > v;
  v.push_back(pair<string, pair<int, int>>("nah", pair<int,int>(90,19961222)));
  v.push_back(pair<string, pair<int, int>>("lee", pair<int,int>(97,19930518)));
  v.push_back(pair<string, pair<int, int>>("park", pair<int,int>(95,19930203)));
  v.push_back(pair<string, pair<int, int>>("han", pair<int,int>(90,19921207)));
  v.push_back(pair<string, pair<int, int>>("kang", pair<int,int>(88,19900302)));
  
  sort(v.begin(), v.end(), cmp);
  for(int i=0; i< v.size(); i++){
    cout<< v[i].first << ' ';
  }

  return 0;
}