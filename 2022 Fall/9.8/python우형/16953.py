import sys
from collections import deque

(A, B) = map(int, sys.stdin.readline().split())

queue = deque()
queue.append((A, 1))            #이 튜플은 해당 노드의 값과 해당 노드까지의 연산 횟수를 나타냄
answer = False

while queue:

    num = queue.popleft()       #num에는 해당 노드에 해당하는 튜플을 저장함

    if num[0] == B:             #목표에 도달하였는지 확인
        print(num[1])
        answer = True           #answer 은 false로 초기화 되어있음, 답을 찾은경우 true로 변환후 반복문 탈출
        break

    if num[0] * 2 <= B:         #각각의 연산의 결과가 B초과시 연산 진행 X 그래야 답이 없는 경우 while문 탈출함
        queue.append((num[0] * 2, num[1] + 1))
    if num[0] * 10 + 1 <= B:
        queue.append((num[0] * 10 + 1, num[1] + 1))

if not answer:                  #답이 없는 경우 -1 출력
    print(-1)