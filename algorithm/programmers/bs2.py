def solution(n, times):
  answer = 0

  times.sort()

  low = 1
  high = times[-1]*n
  
  while low+1 < high :
    mid = (low+high)//2
    print(mid)
    s = 0
    for i in times :
      s += mid//i
    
    if s >= n :
      high = mid
    else :
      low = mid
  
  print(high)
  return high

solution(6, [7,10])