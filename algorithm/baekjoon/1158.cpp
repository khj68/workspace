#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n, m;
  int now=0;
  vector<int> v;

  cin >> n ;
  cin >> m ;

  int len = n;

  for(int i=1; i<=n; i++){
    v.push_back(i);
  }

  // for(int i=0; i<n; i++){
  //   cout << v[i] ;
  // }

  // cout << endl;

  cout << "<" ;
  
  for(int i=0; i<len; i++){
    now += m-1;
    if(now>=n) now %= n;
    // cout << "now : " << now << endl;
    int temp = v[now];
    v.erase(v.begin() + now);

    
    if(n==1) {
      cout << temp << ">";
      break;
    }
    cout << temp << ", " ;
    n -= 1;
  }



  return 0;
}