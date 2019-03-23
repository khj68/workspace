#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

typedef struct brand{
  int six;
  int one;
} branda;

branda* brands[50];

bool cmpOne(branda* a, branda* b){
  return a->one < b->one;
}

bool cmpSix(branda* a, branda* b){
  return a->six < b->six;
}

int main() {
  int need, brand;
  int min = -1, minOne,temp;

  cin >> need >> brand;

  for(int i=0; i< brand; i++) {
    brands[i] = (branda*)malloc(sizeof(brand));
    cin >> brands[i]->six >> brands[i]->one;
  }

  // 1.낱개로만 전부사는 경우
  sort(brands, brands + brand, cmpOne);

  min = brands[0]->one * need;
  minOne = brands[0]->one;
  // 2. 묶음 브랜드 + 낱개브랜드로 사는 경우

  sort(brands, brands + brand, cmpSix);
  temp = brands[0]->six * (need/6) + (need%6) * minOne;
  if(min > temp) min = temp;

  temp = brands[0]->six * (need/6 +1);
  if(min >temp) min = temp;

  cout << min;

  return 0;
}