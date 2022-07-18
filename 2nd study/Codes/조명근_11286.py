import sys
import heapq

n = int(sys.stdin.readline())
lst = [int(sys.stdin.readline()) for _ in range(n)]

hq = []
heapq.heapify(hq)

for x in lst:
    if x < 0:
        heapq.heappush(hq, (-x, x))
    elif x > 0:
        heapq.heappush(hq, (x, x))
    else:
        if len(hq) == 0:
            print("0")
        else:
            print(heapq.heappop(hq)[1])
    print(hq)
