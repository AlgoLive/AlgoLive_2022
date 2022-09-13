# -*-encoding: utf-8 -*-

# 알고리즘 분류 : 그리디
# 문제를 읽어보면 그리디 스럽다...
# 쌀때 사서 비쌀때 팔아야 한다.
# 주식은 최대 하나 살 수 있으므로 날짜별 이득은 
# 그날 -주식가격 + 그날 이후의 최대 가격이다.
# 가장 큰 수를 찾는다. 그 이전의 날들은 모두 그 가격에 판다.
# 그 다음으로 큰 수를 찾는다. 그 이전의 날들은 모두 그 가격에 판다.

# 앞에서부터 counting 용 변수를 활용하여 큰수들로 바꾸어 나간다.
# 뒤에서부터 가장 큰 수들로 배열을 만들어 계산한다.(idea)
import sys

T = int(sys.stdin.readline())

for _ in range(T):
    N = int(sys.stdin.readline())
    stock = list(map(int, sys.stdin.readline().split(" ")))

    profit = []
    profit.append(stock[-1])
    maxStock = stock[-1]
    
    for i in range(len(stock)-1, 0, -1) : 
        maxStock = max(stock[i-1], maxStock)
        profit.append(maxStock)
    profit.reverse()
    answer = 0

    for i, j in zip(profit, stock) :
        answer += (i - j)
    
    print(answer)