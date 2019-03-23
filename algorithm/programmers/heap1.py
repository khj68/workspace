from collections import *
import heapq

def solution(scoville, K):
  answer = 0

  heapq.heapify(scoville)

  while True :
    temp1 = heapq.heappop(scoville)
    if temp1 >= K : break
    if len(scoville) == 0 : return -1
    temp2 = heapq.heappop(scoville)


    heapq.heappush(scoville, temp1 + temp2*2)
    # print(scoville)
    answer += 1
    


  return answer

print(solution([1,2,3,9,10,12], 7))