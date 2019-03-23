from copy import deepcopy

def solution(N, coffe_times) :
  answer = []
  cur = []
  count = 0

  coffe_times = list(zip(coffe_times, range(1, len(coffe_times)+1)))
  print(coffe_times)
  tmp = []
  
  while coffe_times :
    cur = coffe_times[0:N]
    print(cur)
    m = min([x[0] for x in cur])
    cur = list(tuple((x-m,y)) for x, y in cur)
    save_cur = deepcopy(cur)
    print(cur)

    for a,b in cur :
      if a==0 :
        answer.append(b)
        save_cur.pop(save_cur.index((a,b)))
    
    coffe_times = save_cur + coffe_times[N:]
    
   
      

  

  
  return answer

solution(1, [100,1,50,1,1])