n = int(input())


dp = [[-1]*3 for _ in range(n)]
cost = []
for i in range(n) :
    cost.append(list(map(int, input().split())))


# print(cost)

# print(dp)


for i in range(n) :
  if i == 0 :
    dp[i][0] = cost[i][0]
    dp[i][1] = cost[i][1]
    dp[i][2] = cost[i][2]
    continue

  dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2])
  dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2])
  dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1])

print(min(dp[i][0], dp[i][1], dp[i][2]))
  