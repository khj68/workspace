def solution(budgets, M):
  budgets.sort()
  a = sum(budgets)
  if(a <= M):
    return budgets[-1]
  else :
    low = 0
    high = M
    
    while low+1 < high :
      mid = (low+high)//2
      s = 0

      for i in budgets :
        if i < mid :
          s += i
        else :
          s += mid

      if s <= M :
        low = mid
      else :
        high = mid
  
  print(low)
  return low
    

solution([120,110,140,150], 485)