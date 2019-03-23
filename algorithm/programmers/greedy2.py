def solution(number, k):
  answer = ''
  deleted = 0
  string = [a for a in str(number)]
  # 자기보다 큰 걸 만나면 지운다. delete when next is bigger than now
  # print(string[len(string)-1])
  index = 0
  for i, a in enumerate(string) :
    if int(string[0]) < int(a) or index == k:
      deleted += index
      string = string[index:]
      break
    index += 1
    
  
  for i, a in enumerate(string):
    if i+1 < len(string) and int(string[i+1]) > int(a) and deleted <= k:
      deleted += 1
    else :
      answer += a

 
      
  return answer

solution(1231234, 2)
solution(1924, 2)
solution(4177252841, 4)