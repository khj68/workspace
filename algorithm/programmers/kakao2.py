def solution(N, stages):
  answer = []
  stages.sort()
  length = len(stages)
  # print(stages)
  m = {}

  for i, stage in enumerate(stages) :
    if stages[i-1] != stage :
      m[stage] = [1, length-i]
    elif stage not in m.keys() :
      m[stage] = [1, 1]
    else :    
      m[stage][0] += 1

  for stage in range(1, N+1) :
    if stage not in m.keys() :
      m[stage] = 0
    else :
      m[stage] = m[stage][0]/m[stage][1]
  # print(m)
  if N+1 in m.keys(): 
    m.pop(N+1)
  # sorted(m.items(), key=lambda k : m[1], reverse = True)
  a= sorted(m.items(), key=lambda k : k[1], reverse = True)
  print(a)
  answer = [x[0] for x in a]
  # print(answer)
  return answer


solution(5, [2, 1, 2, 6, 2, 4, 3, 3])
solution(4, [4,4,4,4,4])