def solution(people, limit):
  answer = 0
  length = len(people)
  i = 0
  people.sort()
  # print(people)
  heavy = length - 1
  while i<heavy :
    if people[i] + people[heavy] <= limit :
      answer += 1
      i += 1
      heavy -= 1
    else :
      heavy -= 1
    
  
  # print(length - answer)

  return length - answer


solution([70,50,80,50], 100)
solution([70,80,50], 100)