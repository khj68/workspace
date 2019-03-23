#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  vector<float> score;
  int n;

  cin >> n;
  cout << fixed;
  cout.precision(3);

  for(int i=0; i<n; i++){
    float temp;
    cin >> temp;
    score.push_back(temp);
  }

  sort(score.begin(), score.end());

  for(int i=0; i<7; i++){
    cout << score[i] << endl;
  }
  

  return 0;
}