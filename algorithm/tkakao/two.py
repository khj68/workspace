def solution(moves) :
  answer = 0
  axis = set()
  axis.add((0,0))
  currentX = 0
  currentY = 0
  L, U, D, R = 0,0,0,0
  for c in moves :
    if c == 'U' :
      currentY += 1
      U += 1
      axis.add((currentX, currentY))
      
    elif c == 'R' :
      currentX += 1
      R += 1
      axis.add((currentX, currentY))
      
    elif c == 'L' :
      currentX -= 1
      L += 1
      axis.add((currentX, currentY))
      
    elif c == 'D' :
      currentY -= 1
      D += 1
      axis.add((currentX, currentY))
      
    
    
    # print((currentX, currentY))
  # print(axis)
  

  
  answer = min(moves.count('U'), moves.count('R'), moves.count('D'), moves.count('L'))
  if len(moves) % 4 != 0 :
    answer -= 1

  if len(axis) == 4 :
    answer -= 1
  # print(moves.count('U'))
  # print(moves.count('R'))
  # print(moves.count('D'))
  # print(moves.count('L'))
  # print(answer)
  return answer

solution(['U','R','D','L','U','R','D','L'])

solution(['U','U','R','D','L','L','L','U','R','D','D','D','L','U','R','R','R','D','L','U'])
# print()
solution(['U','L','D','R','R','D','D','L','U','U'])