from collections import deque

n = int(input())
routes = [list() for i in range(n)]
maps = [dict() for i in range(n)]
for i in range(n):
    routes[i] = list(map(int, input().split()))
    for k in routes[i]:
        maps[i].setdefault(k, 69)

start, end = list(map(int, input().split()))
# print(start, end)

adj = [list() for i in range(n)]
for i in range(n):
    for k in routes[i]:
        for j in range(i + 1, n):
            if maps[j].get(k, 0) == 69:
                adj[i].append(j)
                adj[j].append(i)

frontier = deque()
visited = [False for i in range(n)]
targets = dict()
for i in range(n):
    if maps[i].get(start, 0) == 69:
        frontier.append((i, 1))
        visited[i] = True
    if maps[i].get(end, 0) == 69:
        targets[i] = 69

valid = False

while len(frontier) > 0 and start != end:
    src, dist = frontier.popleft()
    if targets.get(src, 0) == 69:
        print(dist)
        valid = True
        break
    for dest in adj[src]:
        if not visited[dest]:
            frontier.append((dest, dist + 1))
            visited[dest] = True

if start == end:
    valid = True
    print(0)

if not valid:
    print(-1)
