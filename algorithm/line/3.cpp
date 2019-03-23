#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

int countSpace(string a){
  int ans=0;
  for(int i=0; i<a.size(); i++){
    if( a[i] == ' ') ans++;
  }
  return ans;
}

vector<string> seperateHead(string tmp){
  vector<string> a;
  char s[50]={0,};
  int ptr=0;
  for(int i=0; i<tmp.size(); i++){
    if(tmp[i] == ' ' || tmp[i] == '\n'){
      a.push_back(string(s));
      memset(s, 0, sizeof(s));
      ptr=0;
      continue;
    }
    s[ptr] = tmp[i];
    ptr++;
  }
  a.push_back(string(s));
  
  return a;
}

int main(){
  int l,r;
  int lhNum, rhNum;
  map<int ,vector<string>> m;
  vector<string> lh,rh;
  vector<int> ids;
  int id;
  string tmp, trash;
  int maxSize = 0;

  cin >> l;
  getline(cin, trash);
  for(int i=0; i<l; i++){
    if(i==0){
      getline(cin, tmp);
      lhNum = countSpace(tmp)+1;
      lh = seperateHead(tmp);
      continue;
    }
    cin >> id;
    ids.push_back(id);
    for(int j=0; j<lhNum -1; j++){
      cin >> tmp;
      m[id].push_back(tmp);
    }
  }
  cin >> r;
  getline(cin, trash);
  for(int i=0; i<r; i++){
    if(i==0){
      getline(cin, tmp);
      rhNum = countSpace(tmp)+1;
      rh = seperateHead(tmp);
      continue;
    }
    cin >> id;
    for(int j=0; j<rhNum-1; j++){
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
    int temp = m[ids[i]].size();
    maxSize = max(maxSize, temp);
  }

  for(int i=0; i<ids.size(); i++){
    cout << ids[i] <<" ";
    for(int j=0; j<m[ids[i]].size(); j++){
      cout << m[ids[i]][j] <<" ";
    }
    if(m[ids[i]].size() != maxSize){
      for(int k=0; k<maxSize-m[ids[i]].size(); k++){
        cout << "NULL ";
      }
    }
    cout  << endl;
  }

  return 0;
}