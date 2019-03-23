import heapq
def solution(jobs):
  answer = 0
  current = 0
  heap = []
  jobs.sort()
  print(jobs)
  BP = 1
  while True :
    
    for index, data in enumerate(jobs) :
      
      if data[0] <= current :
        heapq.heappush(heap, [data[0], data[1]])
      else : break
    
    
    if BP == len(jobs) : break

    
    
    if len(heap) == 0 :
      current += 1
      continue
    
    tmp = heap[0]
    heapq.heappop(heap)
    answer += (current - tmp[0]) + tmp[1]
    current += tmp[1]

    BP += 1
  
  while(len(heap)):
    tmp = heapq.heappop(heap)
    answer += (current - tmp[0]) + tmp[1]
    current += tmp[1]
  



  print(answer//len(jobs))
    
  return answer//len(jobs)



solution([[0,3], [1,9], [2,6]])