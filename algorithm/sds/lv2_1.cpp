#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;


int main(){
  int testNum;

  scanf("%d", &testNum);
  

  for(int i=0; i<testNum; i++){
    int alienNum, misileNum, shieldHP;
    int damage, num;
    int destroyedAlien = 0, totalDamage = 0;
    scanf("%d %d %d", &alienNum, &misileNum, &shieldHP);
    vector< vector<int> > arr(misileNum, vector<int>(2));

    for(int j=0; j<misileNum; j++){
      scanf("%d %d", &damage, &num);
      arr[j][0] = damage;
      arr[j][1] = num;
    }

    sort(arr.begin(), arr.end());

    for(int l =0; l<misileNum; l++){
      if(arr[l][0] >= shieldHP && arr[l][1] >0){
        totalDamage += arr[l][0];
        arr[l][1]--;
        destroyedAlien++;
        if(destroyedAlien == alienNum) break;
        continue;
      }
      for(int m=l+1; m<misileNum; m++){
        if((arr[l][0] + arr[m][0] >= shieldHP) && arr[l][1] > 0 && arr[m][1]>0){
          totalDamage += arr[l][0];
          totalDamage += arr[m][0];
          arr[l][1]--;
          arr[m][1]--;
          destroyedAlien++;
          if(destroyedAlien == alienNum) break;
        }
      }
      if(destroyedAlien == alienNum) break;
    }

    // for (vector<int> vec : arr) {
      
    // for (int n : vec)

    //     printf("%3d ", n);

    // cout << endl;

    // }
    if(destroyedAlien < alienNum) printf("#%d -1\n", i+1);
    else printf("#%d %d\n",i+1, totalDamage);

    for(int k=0; k<arr.size(); k++)
      delete &arr[k];
  }

  


  return 0;
}