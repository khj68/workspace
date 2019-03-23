 for i, n in enumerate(coffe_times) :
    tmp = cur + coffe_times[i:i+N-len(cur)]
    print(tmp)
    
    while len(tmp) == N :
      m = min([x[0] for x in tmp])
      # print(m)
      tmp = list(tuple((x-m,y)) for x, y in tmp)
      j = 0
      while j < len(tmp) : 
        if tmp[j][0] == 0 :
          answer.append(tmp[j][1])
          tmp.pop(tmp.index(tmp[j]))
          count += 1
        else :
          cur.append(tmp[j])
          j+=1