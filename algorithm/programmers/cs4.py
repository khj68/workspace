import math

def solution(brown, red):
  answer = []
  total = brown + red

  for i in range(3, int(math.sqrt(total))+1):
    if total % i == 0:
      a = total // i
      if((a-2)*(i-2) == red):
        answer.append(a)
        answer.append(i)
        break

  print(answer)
  return answer

solution(8,1)