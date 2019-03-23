from copy import deepcopy
from collections import defaultdict, deque

def solution(K, user_scores):
  answer = 0
  rank = {}
  rank_score = defaultdict(lambda  : 0)
  scores = deque()
  

  for s in user_scores :
    name = s.split()[0]
    score = int(s.split()[1])
    scores.append(score)
    scores = deque(sorted(scores ,reverse = True))

    
    if score > rank_score[name] :
      rank_score[name] = score
    else : continue
      # 이때 자기보다 큰것 보다 점수가 크다면 업데이트

    rankList = sorted(rank, key=lambda x : rank[x], reverse = True)

    if len(rank) < K :
      answer += 1
      rank[name] = score
    else :
      if score > scores[K-1] :
        if name in rank :
          if scores.index(rank[name]) - scores.index(score) > 1 :
            answer+=1
            rank[name] = score
        else :
          del rank[rankList[-1]]
          rank[name] = score
          answer += 1
    
    # print(rank)
    # print(scores)
    
  # print(scores)
  # print(rank)
  # print(answer)

    # 최소보다 큰게 들어오면 최소 빼고 새로운 거 넣고 정렬

    
    
  
  return answer


solution(3, ['alex111 100', 'cheries2 200', 'coco 150', 'luna 100', 'alex111 120', 'coco 300', 'cheries2 110'])
# solution(3, ['alex111 100', 'cheries2 200', 'alex111 200', 'cheries2 150', 'coco 50', 'coco 200'])