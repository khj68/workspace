def solution(record):
  answer = []
  log = []
  # print(record)

  m = {}
  
  for s in record :
    message = ''
    id = ''
    nickname = ''
    if len(s.split()) == 3 :
      message, id, nickname = s.split()
    else :
      message, id = s.split()
      log.append([message, id])
      continue

    # print(message, id, nickname)
    if message != 'Change':
      log.append([message, id])
    m[id] = nickname
  # print(log)
  # print(m)

  for mes, id in log :
    if mes == 'Enter' :
      answer.append('%s님이 들어왔습니다.' % m[id])
    elif mes == 'Leave' :
      answer.append('%s님이 나갔습니다.' % m[id])

  # print(answer)
  return answer

solution(["Enter uid1234 Muzi","Enter uidz234 muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"])