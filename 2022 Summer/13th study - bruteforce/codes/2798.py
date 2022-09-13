n, m = map(int, input().split())
lst = list(map(int, input().split()))
result = 0
for i in range(0, n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            tmp = lst[i]+lst[j]+lst[k]
            if tmp > m:
                continue
            else:
                result = max(result, tmp)

print(result)
