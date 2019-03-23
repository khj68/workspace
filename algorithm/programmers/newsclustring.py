def solution(str1, str2) :
  answer = 0
  str1 = str1.lower()
  str2 = str2.lower()
  
  li1 = [str1[i:i+2] for i in range(len(str1)-1) if str1[i:i+2].isalpha()]
  li2 = [str2[i:i+2] for i in range(len(str2)-1) if str2[i:i+2].isalpha()]

  print(li1)
  print(li2)

  hap = 0
  gyo = 0

  for s in set(li1 + li2) :
    hap += max(li1.count(s), li2.count(s))  
    gyo += min(li1.count(s), li2.count(s))

  if hap == 0 : return 65536
  answer = int(gyo / hap * 65536)  

  print(answer)



  return answer

solution('FRANCE' ,'french')