#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
  int n;
  int ans = 100000000;
  cin >> n;

  for(int i=1; i<= sqrt(n); i++){
    if(n%i == 0){
      ans = min(ans, abs(i-(n/i)));
    }
  }
  cout << ans;

  return 0;
}