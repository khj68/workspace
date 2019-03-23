n = int(input())
l = []
s = []
count = 0
temp = 0
for i in range(n) :
  a = int(input())
  
  if len(s) == 0:
    s.append([a,0])
    continue
  
  if a > s[i-1] :
    if len(s) == 1 :
      s.pop()
      s.append([a,0])
      continue
    while s and s[-1] < a:
      s.pop()
      if not s : break
      count += 1
    s.append(a)

  elif a <= l[i-1] :
    s.append(a)
  
  
# print(l)
print(count+len(l)-1)

      

