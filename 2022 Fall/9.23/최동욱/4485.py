# BFS + Djikstra
# 최단거리 및 priority queue의 관점에서는 Djikstra,
# 그래프를 탐색한다는 점에서는 BFS
# 두 개념이 적절히 섞인 아주 재밌는 문제였음
# 개인적으로 어제 본 코테 처럼 두 개념이 섞이면 어렵고 재밌는 것 같습니다~

import sys
from math import inf
from heapq import heappush, heappop

index = 0
while(1):
    index += 1
    N = int(input())
    if (N == 0):
        quit()
    # 루비가 뿌려져 있는 맵
    rub_map = []
    for i in range(N):
        rub_map.append(list(map(int, sys.stdin.readline().split())))

    # 현재 인덱스를 나타냄
    cur_x, cur_y = 0, 0

    # 맵별로 최소 거리를 나타냄
    dist = [[inf for i in range(N)] for i in range(N)]
    dist[cur_x][cur_y] = rub_map[cur_x][cur_y]

    # 맵별로 최소거리를 찾았는지 여부를 저장
    found = [[False for i in range(N)] for i in range(N)]
    # 현재 최단거리를 저장할 heap
    heap = []
    heappush(heap, [rub_map[cur_x][cur_y], 0, 0])

    dx, dy = [1, -1, 0, 0], [0, 0, 1, -1]

    while(len(heap) != 0):
        # heap에서 현재 최소인 인덱스를 저장. 
        cur_dist, cur_x, cur_y = heappop(heap)
        found[cur_x][cur_y] = True
        # 거리 초기화

        for i in range(4):
                next_x, next_y = cur_x + dx[i], cur_y + dy[i]
                if 0 <= next_x < N and 0 <= next_y < N:
                    next_dist = rub_map[next_x][next_y] 
                    if cur_dist + next_dist < dist[next_x][next_y]:
                        heappush(heap, (cur_dist + next_dist, next_x, next_y))
                        dist[next_x][next_y] = cur_dist + next_dist
                        
    print(f"Problem {index}: {dist[N-1][N-1]}")