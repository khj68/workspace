def solution(n, lost, reserve):
  answer = n - len(lost)

  for l in lost :
    if l in reserve :
      answer += 1
      reserve.pop(reserve.index(l))
      continue
    
    if l-1 in reserve :
      answer += 1
      reserve.pop(reserve.index(l-1))
      continue

    if l+1 in reserve :
      answer += 1
      reserve.pop(reserve.index(l+1))

  print(3)

  return answer

solution(5, [1,2,3,4], [3,5])