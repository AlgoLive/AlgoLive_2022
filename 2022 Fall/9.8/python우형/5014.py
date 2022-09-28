<<<<<<< HEAD
# -*-encoding: utf-8 -*-

# 알고리즘 분류 : 그래프, 그래프 탐색, 너비 우선 탐색(BFS)
# BFS를 위한 큐(queue)는 deque()로 구현
# 최단거리 문제 유형, 초기 위치에서 up or down
# 초기위치를 포함하여 한번 방문한 위치는 재방문 X
# 따라서 노드에 포함하여야 하는 정보 : 방문 여부, 몇번째 방문
# 이를 노드의 값을 0 으로 하고 방문노드 = 이전노드 + 1 로 처리
# 처음 위치의 값을 1로 하고 최종 이동횟수를 -1 처리

# BFS임을 파악하기 : 버튼 수의 최소 -> 최단 경로
# up, down을 기준으로 분기하여 그래프(트리모양이긴함)를 그리다 보면
# dfs를 활용할 경우 최단경로가 아닐 가능성이 있음
# 인접한 정도에 따라 depth 가 깊어짐을 알 수 있음
# 왜냐, 트리모양이었어서..(분기개수 2개)
# 암튼 방문한 위치는 재방문이 안되기 때문에 현재 노드에
# 저장된 이동 횟수는 그 위치까지 오기 위한 최소의 이동 횟수이고
# 가장 먼저 발견된 답의 이동경로는 최소 이동 경로 집합의 원소 중
# 하나이다.
import sys
from collections import deque

(F, S, G ,U, D) = map(int, sys.stdin.readline().split())

queue = deque()
queue.append(S)     #queue 에는 현재 위치가 들어감
building = [0]*(F+1)
building[S] = 1
answer = 0

while queue :
    
    location = queue.popleft()
    
    if location == G :
        answer = building[location]
        break

    if location - D >= 1 and building[location - D] == 0 :
        queue.append(location - D)
        building[location - D] = building[location] + 1
    if location + U <= F and building[location + U] == 0 :
        queue.append(location + U)
        building[location + U] = building[location] + 1

if answer == 0 :
    print("use the stairs")
else : 
=======
# -*-encoding: utf-8 -*-

# 알고리즘 분류 : 그래프, 그래프 탐색, 너비 우선 탐색(BFS)
# BFS를 위한 큐(queue)는 deque()로 구현
# 최단거리 문제 유형, 초기 위치에서 up or down
# 초기위치를 포함하여 한번 방문한 위치는 재방문 X
# 따라서 노드에 포함하여야 하는 정보 : 방문 여부, 몇번째 방문
# 이를 노드의 값을 0 으로 하고 방문노드 = 이전노드 + 1 로 처리
# 처음 위치의 값을 1로 하고 최종 이동횟수를 -1 처리

# BFS임을 파악하기 : 버튼 수의 최소 -> 최단 경로
# up, down을 기준으로 분기하여 그래프(트리모양이긴함)를 그리다 보면
# dfs를 활용할 경우 최단경로가 아닐 가능성이 있음
# 인접한 정도에 따라 depth 가 깊어짐을 알 수 있음
# 왜냐, 트리모양이었어서..(분기개수 2개)
# 암튼 방문한 위치는 재방문이 안되기 때문에 현재 노드에
# 저장된 이동 횟수는 그 위치까지 오기 위한 최소의 이동 횟수이고
# 가장 먼저 발견된 답의 이동경로는 최소 이동 경로 집합의 원소 중
# 하나이다.
import sys
from collections import deque

(F, S, G ,U, D) = map(int, sys.stdin.readline().split())

queue = deque()
queue.append(S)     #queue 에는 현재 위치가 들어감
building = [0]*(F+1)
building[S] = 1
answer = 0

while queue :
    
    location = queue.popleft()
    
    if location == G :
        answer = building[location]
        break

    if location - D >= 1 and building[location - D] == 0 :
        queue.append(location - D)
        building[location - D] = building[location] + 1
    if location + U <= F and building[location + U] == 0 :
        queue.append(location + U)
        building[location + U] = building[location] + 1

if answer == 0 :
    print("use the stairs")
else : 
>>>>>>> 36d2869ec230063a227952956cdf2a73c80ddf42
    print(answer-1)