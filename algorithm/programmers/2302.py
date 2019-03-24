seat = int(input())
vipNum = int(input())
vip = []
dp = [1]
for i in range(vipNum) :
  vip.append(int(input()))

print(vip)

for i in range(1, seat) :
  dp[i] = dp[i-1] + 