import heapq



def solution(stock, dates, supplies, k):
    answer = 0
    
    heap = []
    
    start = 0

    data = []
    while stock < k :
      for i in range(start,len(dates)) :
        if dates[i] <= stock :
          heapq.heappush(heap, (-supplies[i], supplies[i]))
        else:
          start = i
          break
    
      answer += 1
      stock += heap[0][1]
      heapq.heappop(heap)
      # print(heap)
      # print(start)

    print(answer)
    
    return answer

solution(4,[4,10,15], [20,5,10], 30)