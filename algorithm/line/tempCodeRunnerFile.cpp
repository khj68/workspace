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