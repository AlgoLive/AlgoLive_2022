import sys
import heapq

def input():
    return sys.stdin.readline().rstrip()

heap = []

N = int(input())

for i in range (N):
    num = int(input())
    if num == 0:
        if heap:
            print(heapq.heappop(heap)[1])
        else:
            print(0)
    else:
        heapq.heappush(heap, (-num, num))  # (우선 순위, 값)
