import sys
from itertools import combinations

n = int(input())
arr = []

for _ in range(n):
    arr.append(list(map(int, input().split())))

com = []
for i in range(1, n+1):
    com.append(combinations(arr, i))
answer = 100000000

for i in com:
    for j in i:
        sour = 1
        bitter = 0
        for e in j:
            sour *= e[0]
            bitter += e[1]

        answer = min(answer, abs(sour-bitter))
print(answer)
