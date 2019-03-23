from collections import defaultdict

def nextWord(cur, words):
    ret = []
    for word in words:
        if sum([word[i] != cur[i] for i in range(len(word))]) == 1:
            ret.append(word)
    # print(ret)
    return ret

def bfs(begin, target, words):
    visited = defaultdict(lambda: False)
    queue = nextWord(begin, words)
    level = 0

    while(len(queue) > 0):
        size = len(queue)
        level += 1
        print(queue)

        for _ in range(size):
            key = queue.pop(0)
            visited[key] = True
            if (key == target):
                return level
            for candidate in nextWord(key, words):
                if (visited[candidate] == False):
                    queue.append(candidate)

    return 0

def solution(begin, target, words):
    answer = bfs(begin, target, words)
    print(answer)
    return answer

solution('hit', 'cog', ['hot','dot','dog','lot','log','cog'])