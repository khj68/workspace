#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(){
  int l,r;
  map<int ,vector<string>> m;
  vector<string> lh,rh;
  vector<int> ids;
  int id;
  string tmp;

  cin >> l;
  for(int i=0; i<l; i++){
    if(i==0){
      for(int j=0; j<3; j++){
        cin >> tmp;
        lh.push_back(tmp);
      }
      continue;
    }
    cin >> id;
    ids.push_back(id);
    for(int j=1; j<3; j++){
      cin >> tmp;
      m[id].push_back(tmp);
    }
  }
  cin >> r;
  for(int i=0; i<r; i++){
    if(i==0){
      for(int j=0; j<3; j++){
        cin >> tmp;
        rh.push_back(tmp);
      }
      continue;
    }
    cin >> id;
    for(int j=1; j<3; j++){
      cin >> tmp;
      if(m[id].size() == 0) continue;
      m[id].push_back(tmp);
    }
  }
  sort(ids.begin(), ids.end());
  for(int i=0; i<lh.size(); i++){
    cout << lh[i] <<" ";
  }
  for(int i=1; i<rh.size(); i++){
    cout << rh[i] <<" ";
  }
  cout << endl;

  for(int i=0; i<ids.size(); i++){
    cout << ids[i] <<" ";
    for(int j=0; j<m[ids[i]].size(); j++){
      cout << m[ids[i]][j] <<" ";
    }
    if(m[ids[i]].size() == 2){
      cout << "NULL NULL";
    }
    cout  << endl;
  }

  return 0;
}