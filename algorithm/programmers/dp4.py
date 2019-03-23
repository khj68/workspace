def solution(m, n, puddles):
  answer = 0
  ma = []
  d = []
  for i in range(102) :
    ma.append([])
    d.append([])
    for j in range(102) :
      ma[i].append(0)
      d[i].append(0)
  
  for v in puddles :
    ma[v[1]][v[0]] = -1
  
  d[1][0] = 1
  for i in range(1, n+1) :
    for j in range(1, m+1) :
      if ma[i][j] == -1 :
        d[i][j] = 0
      else :
        d[i][j] = (d[i-1][j] + d[i][j-1]) % 1000000007

  
  return d[n][m]

solution(4,3, [[2, 2]])