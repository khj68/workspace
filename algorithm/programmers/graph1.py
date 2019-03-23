def solution(n, edge):
  answer = 0
  edge.sort()
  print(edge)
  s = set()
  s.update((1,0))
  distance = 1
  for a, b in edge :

    if a in s. :
      set.update((b, distance))
      distance += 1

  

  return answer

solution(6, [[3, 6], [4, 3], [3, 2], [1, 3], [1, 2], [2, 4], [5, 2]])