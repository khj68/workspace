candidates = []
def visit(start, graph, visited, cnt, route):
    print(route)
    global candidates
    if cnt == len(graph):
        candidates.append(route.split(" "))
    else:
        for i in range(len(graph)):
            if visited[i] == 0 and graph[i][0] == start:
                go = []
                for j in range(len(visited)):
                    go.append(visited[j])
                
                go[i] = 1
                print(go)
                visit(graph[i][1], graph, go, cnt+1, route+" "+graph[i][1])

def solution(tickets):
    answer = []
    tickets.sort()
    visited = [0] * len(tickets)
    print(tickets)
    print(visited)
    visit("ICN", tickets, visited, 0, "ICN")
    print(candidates)
    return candidates[0]

solution([['ICN', 'SFO'], ['ICN', 'ATL'], ['SFO', 'ATL'], ['ATL', 'ICN'], ['ATL','SFO']])