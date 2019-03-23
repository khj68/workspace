
n = int(input())

dp = [0 for _ in range(101)]
for i in range(1,n+1) :
  dp[i] = i
  dp[i] = max(dp[i], dp[i-1]+1)
  for j in range(3, 6) :
    if i-j >= 0 :
      dp[i] = max(dp[i-j] * (j-1), dp[i])
  
print(dp[n])