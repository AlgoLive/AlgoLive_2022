# -*-encoding: utf-8 -*-

# �˰��� �з� : �׸���
# ������ �о�� �׸��� ������...
# �Ҷ� �缭 ��Ҷ� �Ⱦƾ� �Ѵ�.
# �ֽ��� �ִ� �ϳ� �� �� �����Ƿ� ��¥�� �̵��� 
# �׳� -�ֽİ��� + �׳� ������ �ִ� �����̴�.
# ���� ū ���� ã�´�. �� ������ ������ ��� �� ���ݿ� �Ǵ�.
# �� �������� ū ���� ã�´�. �� ������ ������ ��� �� ���ݿ� �Ǵ�.

# �տ������� counting �� ������ Ȱ���Ͽ� ū����� �ٲپ� ������.
# �ڿ������� ���� ū ����� �迭�� ����� ����Ѵ�.(idea)
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