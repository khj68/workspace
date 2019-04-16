int solution(vector<int> &T) {
  int warmest_winter = T[0];
  int length_winter = 1;
  int size = T.size();
  for(int i=1; i<size; i++){
    if(T[i] > warmest_winter) {
      int threshold = T[i];
      for(int j=i+1; j<size; j++){
        if(T[j] > threshold) threshold = T[j];
        if(T[j] <= warmest_winter){
          length_winter = j+1;
          for(int k= j+1; k<size; k++){
            if(T[k] <= threshold){
              length_winter = k+1;
            }
          }
          break;
        }
      }
      break;
    }
    length_winter++;
  }
  return length_winter;
}