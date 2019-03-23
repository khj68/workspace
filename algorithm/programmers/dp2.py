def solution(N):
  answer = 0
  fib = [0, 1]

  for i in range(2, N+1) :
    fib.append(fib[i-1]+fib[i-2])

  print(fib)

  row = fib[-1] + fib[-2]
  col = fib[-2] + fib[-3]

  answer = 2*(row+col)
  print(answer)
  return answer

solution(5)
solution(6)