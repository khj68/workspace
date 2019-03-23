memory = [0 for _ in range(1000001)]

def dp(n) :
  global memory

  for i in range(2, n+1) :
    memory[i] = memory[i-1] + 1

    if(i % 2 == 0) :
      memory[i] = min(memory[i], memory[i//2] + 1)
    
    if(i % 3 == 0) :
      memory[i] = min(memory[i], memory[i//3] + 1)



n = int(input())
dp(n)
print(memory[n])