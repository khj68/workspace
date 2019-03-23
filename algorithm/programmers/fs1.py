index = 0
count = 0
def dfs(n, depth, s, numbers, t) :
  global count
  s += n

  if depth +1 == len(numbers) :
    if s == t : count += 1
    return
  dfs(numbers[depth+1], depth+1, s, numbers, t)
  dfs(-numbers[depth+1], depth+1, s, numbers, t)





def solution(numbers, target):
  global index
  answer = 0

  dfs(numbers[0], 0, 0, numbers,target)
  dfs(-numbers[0],0 ,0 , numbers, target)

  print(count)
  return count

solution([1,1,1,1,1], 3)