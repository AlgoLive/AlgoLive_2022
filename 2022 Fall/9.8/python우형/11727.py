# -*-encoding: utf-8 -*-

# 알고리즘 분류 : 다이나믹 프로그래밍
# 문제 풀이는 규칙을 찾아 점화식을 세워 계산하는것.
# 규칙 대신 아래와 같이 중복을 허용하여 나열하는 경우의 수를
# 계산할 수 있음. N = 1000이고 두개의 while문은 최대 500번 반복하므로
# 2500번보다 적게 반복함.. 1억당 1초이므로,, 충분히 가능하다고 생각
# 하였으나 math.factorial()의 시간복잡도가 복잡한가보다.. python3에서는
# 시간초과가 나오며, pypy3에서는 어쨋든 성공한다..

import sys
import math

N = int(sys.stdin.readline())
num = 0
a = 0
if N % 2 == 0 : #짝수
    c = 0
    while (c <= N ) :
        a = 0
        while( a <= (N-c)//2) :
            b = (N-c)//2 - a
            num += math.factorial(a + b + c) // (math.factorial(a) * math.factorial(b) * math.factorial(c))
            a += 1
        c += 2
elif N % 2 == 1 : #홀수
    c = 1
    while (c <= N ) :
        a = 0
        while( a <= (N-c)//2) :
            b = (N-c)//2 - a
            num += math.factorial(a + b + c) // (math.factorial(a) * math.factorial(b) * math.factorial(c))
            a += 1
        c += 2

print(num%10007)