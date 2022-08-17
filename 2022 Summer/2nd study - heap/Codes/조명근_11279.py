import heapq
import sys

n = int(sys.stdin.readline())
lst = [int(sys.stdin.readline()) for _ in range(n)]

hq = []
heapq.heapify(hq)
for x in lst:
    if x == 0:
        if len(hq) > 0:
            print(-heapq.heappop(hq))
        else:
            print("0")

    elif x > 0:
        heapq.heappush(hq, -x)
