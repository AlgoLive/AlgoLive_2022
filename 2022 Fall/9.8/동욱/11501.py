T = int(input())

while T > 0:
    N = int(input())
    prices = list(map(int, input().split()))
    max, profit, end = 0, 0, len(prices) - 1
    for i in range(end, -1, -1):
        if prices[i] > max:
            max = prices[i]
        else:
            profit += max - prices[i]
    print(profit)
    T -= 1
