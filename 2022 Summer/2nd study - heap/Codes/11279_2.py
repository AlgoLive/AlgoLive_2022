import sys
# import heapq
from queue import PriorityQueue

def input():
    return sys.stdin.readline().rstrip()

heap = PriorityQueue()

N = int(input())

for i in range (N):
    num = int(input())
    if num == 0:
        if heap.empty():
            print(0)
        else:
            print(heap.get()[1])
    else:
        heap.put((-num, num))  # (우선 순위, 값)