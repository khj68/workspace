def isPrime(n, i=2):
  if n<i:
    return False
  while i*i <= n :
    if not n % i :
      return False
    i += 1
  return True

def get_int(case):
  n_str = "".join([str(i) for i in case])
  return int(n_str[1:] if len(n_str) > 1 and n_str[0] == '0' else n_str)


def solution(numbers):
  answer = list()
  numbers = [int(n) for n in numbers]
  import itertools
  for repeat in range(1, len(numbers)+1):
    for num in set((get_int(x) for x in itertools.permutations(numbers, repeat))):
      if num not in answer and isPrime(num):
        answer.append(num)
      
  return len(answer)

solution('17309')