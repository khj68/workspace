seat = int(input())
vipN = int(input())
dp = [1,1]
vip = []
answer = 1
index = 0

for i in range(vipN) :
  vip.append(int(input()))


for i in range(2, 40+1) :
  dp.append(dp[-2] + dp[-1])
# print(dp)

for i in range(1, seat+1) :
  if i in vip :
    answer *= dp[index]
    index = 0
  else :
    index += 1

  if i == seat :
    answer *= dp[index]

if seat == vipN :
  answer = 1

print(answer)
