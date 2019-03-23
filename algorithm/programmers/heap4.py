def solution(operations):
  import heapq
  answer = []
  pq = []

  for operation in operations:
    op, num = operation.split()

    if op == 'I':
      heapq.heappush(pq, int(num))
    elif op == 'D' and pq :
      if num == '1':
        data = max(pq)
        pq.pop(pq.index(data))
      elif num == '-1':
        heapq.heappop(pq)
    
  if pq :
    answer.append(max(pq))
    answer.append(heapq.heappop(pq))
  else:
    answer = [0,0]
  return answer