<<<<<<< HEAD
from collections import deque

F, S, G, U, D = tuple(map(int, input().split()))
# F -> Floor, S -> Current, G -> Target, U -> Up, D -> Down

current = S
count = 0

queue = deque([current])
visited = [0 for i in range(F + 1)]
visited[current] = 1

while queue:
    current = queue.popleft()
    if current == G:
        print(visited[current] - 1)
        quit()
    if current + U <= F and not visited[current + U]:
        visited[current + U] = visited[current] + 1
        queue.append(current + U)
    if current - D > 0 and not visited[current - D]:
        visited[current - D] = visited[current] + 1
        queue.append(current - D)

print("use the stairs")
=======
from collections import deque

F, S, G, U, D = tuple(map(int, input().split()))
# F -> Floor, S -> Current, G -> Target, U -> Up, D -> Down

current = S
count = 0

queue = deque([current])
visited = [0 for i in range(F + 1)]
visited[current] = 1

while queue:
    current = queue.popleft()
    if current == G:
        print(visited[current] - 1)
        quit()
    if current + U <= F and not visited[current + U]:
        visited[current + U] = visited[current] + 1
        queue.append(current + U)
    if current - D > 0 and not visited[current - D]:
        visited[current - D] = visited[current] + 1
        queue.append(current - D)

print("use the stairs")
>>>>>>> 36d2869ec230063a227952956cdf2a73c80ddf42
