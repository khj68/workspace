def solution(phone_number) :
  answer = 0
  if phone_number[:4] == '010-' : return 1
  elif phone_number[:3] == '010' : return 2
  elif phone_number[:3] == '+82' : return 3
  else : return -1
  


  return answer




print(solution('01012345678'))