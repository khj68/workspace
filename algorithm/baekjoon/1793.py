from sys import stdin
for n in map(int, stdin.read().split()) :
  dp = [0 for x in range(1002)]

  dp[0] = 1
  dp[1] = 1
  for i in range(2, n+1) :
    dp[i] = (dp[i-1] + dp[i-2]*2)

  print(dp[n])
