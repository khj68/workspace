def solution(baseball):
  answer = 0

  rs = list(filter(lambda x: '0' not in x and len(set(x)) == 3, list(map(str,range(111,1000)))))
  for b in baseball:
    i=0
    while len(rs) and i < len(rs):
      ss,st,bl = str(b[0]), 0, 0
      for j in range(len(ss)):
        if rs[i][j] in ss:
          if ss.index(rs[i][j]) == j:
            st += 1
          else:
            bl += 1
      if st != b[1] or bl != b[2]:
        rs.pop(i)
      else:
        i+= 1
  print(len(rs))
  return len(rs)

solution([[123, 1, 1], [356, 1, 0], [327, 2, 0], [489, 0, 1]])