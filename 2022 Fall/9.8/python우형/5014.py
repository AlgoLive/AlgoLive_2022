<<<<<<< HEAD
# -*-encoding: utf-8 -*-

# �˰��� �з� : �׷���, �׷��� Ž��, �ʺ� �켱 Ž��(BFS)
# BFS�� ���� ť(queue)�� deque()�� ����
# �ִܰŸ� ���� ����, �ʱ� ��ġ���� up or down
# �ʱ���ġ�� �����Ͽ� �ѹ� �湮�� ��ġ�� ��湮 X
# ���� ��忡 �����Ͽ��� �ϴ� ���� : �湮 ����, ���° �湮
# �̸� ����� ���� 0 ���� �ϰ� �湮��� = ������� + 1 �� ó��
# ó�� ��ġ�� ���� 1�� �ϰ� ���� �̵�Ƚ���� -1 ó��

# BFS���� �ľ��ϱ� : ��ư ���� �ּ� -> �ִ� ���
# up, down�� �������� �б��Ͽ� �׷���(Ʈ������̱���)�� �׸��� ����
# dfs�� Ȱ���� ��� �ִܰ�ΰ� �ƴ� ���ɼ��� ����
# ������ ������ ���� depth �� ������� �� �� ����
# �ֳ�, Ʈ������̾��..(�бⰳ�� 2��)
# ��ư �湮�� ��ġ�� ��湮�� �ȵǱ� ������ ���� ��忡
# ����� �̵� Ƚ���� �� ��ġ���� ���� ���� �ּ��� �̵� Ƚ���̰�
# ���� ���� �߰ߵ� ���� �̵���δ� �ּ� �̵� ��� ������ ���� ��
# �ϳ��̴�.
import sys
from collections import deque

(F, S, G ,U, D) = map(int, sys.stdin.readline().split())

queue = deque()
queue.append(S)     #queue ���� ���� ��ġ�� ��
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

# �˰��� �з� : �׷���, �׷��� Ž��, �ʺ� �켱 Ž��(BFS)
# BFS�� ���� ť(queue)�� deque()�� ����
# �ִܰŸ� ���� ����, �ʱ� ��ġ���� up or down
# �ʱ���ġ�� �����Ͽ� �ѹ� �湮�� ��ġ�� ��湮 X
# ���� ��忡 �����Ͽ��� �ϴ� ���� : �湮 ����, ���° �湮
# �̸� ����� ���� 0 ���� �ϰ� �湮��� = ������� + 1 �� ó��
# ó�� ��ġ�� ���� 1�� �ϰ� ���� �̵�Ƚ���� -1 ó��

# BFS���� �ľ��ϱ� : ��ư ���� �ּ� -> �ִ� ���
# up, down�� �������� �б��Ͽ� �׷���(Ʈ������̱���)�� �׸��� ����
# dfs�� Ȱ���� ��� �ִܰ�ΰ� �ƴ� ���ɼ��� ����
# ������ ������ ���� depth �� ������� �� �� ����
# �ֳ�, Ʈ������̾��..(�бⰳ�� 2��)
# ��ư �湮�� ��ġ�� ��湮�� �ȵǱ� ������ ���� ��忡
# ����� �̵� Ƚ���� �� ��ġ���� ���� ���� �ּ��� �̵� Ƚ���̰�
# ���� ���� �߰ߵ� ���� �̵���δ� �ּ� �̵� ��� ������ ���� ��
# �ϳ��̴�.
import sys
from collections import deque

(F, S, G ,U, D) = map(int, sys.stdin.readline().split())

queue = deque()
queue.append(S)     #queue ���� ���� ��ġ�� ��
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