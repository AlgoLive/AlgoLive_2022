# -*-encoding: utf-8 -*-

# �˰��� �з� : ���̳��� ���α׷���
# ���� Ǯ�̴� ��Ģ�� ã�� ��ȭ���� ���� ����ϴ°�.
# ��Ģ ��� �Ʒ��� ���� �ߺ��� ����Ͽ� �����ϴ� ����� ����
# ����� �� ����. N = 1000�̰� �ΰ��� while���� �ִ� 500�� �ݺ��ϹǷ�
# 2500������ ���� �ݺ���.. 1��� 1���̹Ƿ�,, ����� �����ϴٰ� ����
# �Ͽ����� math.factorial()�� �ð����⵵�� �����Ѱ�����.. python3������
# �ð��ʰ��� ������, pypy3������ ��¶�� �����Ѵ�..

import sys
import math

N = int(sys.stdin.readline())
num = 0
a = 0
if N % 2 == 0 : #¦��
    c = 0
    while (c <= N ) :
        a = 0
        while( a <= (N-c)//2) :
            b = (N-c)//2 - a
            num += math.factorial(a + b + c) // (math.factorial(a) * math.factorial(b) * math.factorial(c))
            a += 1
        c += 2
elif N % 2 == 1 : #Ȧ��
    c = 1
    while (c <= N ) :
        a = 0
        while( a <= (N-c)//2) :
            b = (N-c)//2 - a
            num += math.factorial(a + b + c) // (math.factorial(a) * math.factorial(b) * math.factorial(c))
            a += 1
        c += 2

print(num%10007)