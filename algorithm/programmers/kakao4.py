def solution(nodeinfo):
  answer = [[]]
  nodeinfo.sort(key = lambda a : a[0])
  print(nodeinfo)
  nodeinfo.sort(key = lambda a : a[1], reverse= True)
  
  print(nodeinfo)
  return answer

solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]])