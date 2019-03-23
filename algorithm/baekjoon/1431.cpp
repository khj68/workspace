#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cctype>

using namespace std;

int n;
string arr[1000];

bool compare(string& a, string& b){
  if(a.size() != b.size()) return a.size() < b.size();
  
  isdigit('a');
  int aSum=0, bSum=0;
  for(int i=0; i< a.size(); i++){
    if(isdigit(a[i])) aSum += a[i]-'0';
    if(isdigit(b[i])) bSum += b[i]-'0';
  }
  if(aSum != bSum) return aSum < bSum;

  return a<b;
}

int main(){
  cin >> n;
  for(int i=0; i<n; i++){
    cin >> arr[i];
  }
  sort(arr, arr+n, compare);

  for(int i=0; i<n; i++){
    cout << arr[i] << endl;
  }
}