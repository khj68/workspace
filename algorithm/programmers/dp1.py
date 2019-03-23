l = []
count = 0
minCount = 9

def bfs(N, number) :
  global count
  global minCount
  global l
  if count >= minCount : return
  if len(l) >= minCount : return
  
  lastNumber = 0 if len(l) == 0 else l[len(l)-1]

  if lastNumber == number :
    minCount = min(count, minCount)
    return

  n = 0
  addCount = 0

  for c in range(0, 8) :
    addCount += 1
    if count + addCount >= minCount : continue
    
    n += N*(10**c)

    count += addCount

    l.append(lastNumber+n)
    bfs(N,number)
    l.pop()

    if lastNumber - n != 0 :
      l.append(lastNumber-n)
      bfs(N, number)
      l.pop()

    l.append(lastNumber*n)
    bfs(N,number)
    l.pop()

    if lastNumber / n != 0 :
      l.append(lastNumber/n)
      bfs(N,number)
      l.pop()
    
    count -= addCount

  return


def solution(N, number):

  bfs(N,number)

  return minCount if minCount<9 else -1

print(solution(12,2))