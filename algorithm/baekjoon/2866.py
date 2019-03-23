r, c = map(int,input().split())
count = 0
l = []
l2 = []

for i in range(r) :
  l.append([a for a in input()])

for i in range(c) :
  l2.append('')

  for j in range(r) :
    l2[i] += l[j][i]

while True :
  se = set()
  for i,s in enumerate(l2) :
    l2[i] = l2[i][1:]
    se.add(l2[i])
  print(l2)
  if len(se) != c :
    break
  
  
  count += 1


print(count)
