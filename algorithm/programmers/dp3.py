
def solution(triangle):
  answer = 0

  for i, l in enumerate(triangle) :
    if i == 0 : continue
    if i == 1 : 
      l[0] += triangle[0][0]
      l[1] += triangle[0][0]
      continue
    for j, a in enumerate(l) :
      if j == 0 :
        l[0] += triangle[i-1][0]
        continue
      if j == len(l)-1 :
        l[-1] += triangle[i-1][-1]
        continue

      l[j] += max(triangle[i-1][j-1], triangle[i-1][j])  
        
      
  

  # print(triangle[-1])


  return max(triangle[-1])


a = int(input())
l = []
for i in range(1,a+1) :
  l.append([])
  l[i-1] = list(map(int, input().split()))
print(solution(l))