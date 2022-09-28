# DP
# 으헝헝 DP 너무 어려워요...
# 도저히 모르겠어서 무수히 많은 if문으로 처리하려다가
# 살짝 참고해서 맞췄다

import sys

def checker(n, m, map, arr):
    temp = [arr[n][m-1], arr[n-1][m], arr[n-1][m-1]]
    if map[n][m]:
        t = min(temp)
        if t > 0:
            return t + 1
        else:
            return 1
    else:
        return 0

n, m = map(int, sys.stdin.readline().split())

map_array = []
ans_array = [[0 for _ in range(m)] for _ in range(n)]

for _ in range(n):
    temp = input()
    map_array.append(list(map(int, temp)))

ans_array[0] = map_array[0]

for l in range(n):
    ans_array[l][0] = map_array[l][0]

for l in range(1, n):
    temp = list()
    for i in range(1, m):
        ans_array[l][i] = checker(l, i, map_array, ans_array)

max_num = 0
for l in range(n):
    if max_num < max(ans_array[l]):
        max_num = max(ans_array[l])

print(max_num * max_num)
