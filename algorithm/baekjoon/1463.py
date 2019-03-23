from collections import deque

n = int(input())

q = deque()

q.append((n, 0))

while q : 
  temp = q.popleft()
  if temp[0] == 1 :
    print(temp[1])
    break
  if temp[0] % 3 == 0 :
    q.append((temp[0]//3, temp[1]+1))

  if temp[0] % 2 == 0 :
    q.append((temp[0]//2, temp[1]+1))

  q.append((temp[0]-1, temp[1]+1))