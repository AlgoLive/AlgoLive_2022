# BFS 문제
# 2차원 배열 n, m이 바뀌어 인덱스 에러 때문에 너무 고생했다
# 그래프 문제 나올 때 x, y가 정확히 설정됐는지 확인 필요
# BFS의 구현 자체는 일반적임

from math import inf
from collections import deque
import sys

n, m = map(int, sys.stdin.readline().rstrip().split())
graph = list()

for i in range(n):
    line = list(map(int, sys.stdin.readline().split()))
    graph.append(line)

for x in range(n):
    for y in range(m):
        if graph[x][y] == 2:
            s_x, s_y = x, y
        
visited = [[False for _ in range(m)] for _ in range(n)]
dist = [[-1 for _ in range(m)] for _ in range(n)]
dist[s_x][s_y] = 0

q = deque()
q.append((s_x, s_y))
dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

while q:
    cur = q.popleft()
    cur_x, cur_y = cur[0], cur[1]
    cur_dist = dist[cur_x][cur_y]
    if visited[cur_x][cur_y]:
        continue
    visited[cur_x][cur_y] = True

    for i in range(4):
        next_x = cur_x + dx[i]
        next_y = cur_y + dy[i]
        if 0 <= next_x < n and 0 <= next_y < m:
            if not visited[next_x][next_y] and graph[next_x][next_y] != 0:
                dist[next_x][next_y] = cur_dist + 1
                q.append((next_x, next_y))

for x in range(n):
    for y in range(m):
        if graph[x][y] == 0:
            dist[x][y] = 0

for x in range(n):
    for y in range(m):
        print(dist[x][y], end=' ')
    print()
