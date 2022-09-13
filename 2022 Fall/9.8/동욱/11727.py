N = int(input())

memo = [0 for i in range(1001)]

def dp(N: int) -> N:
    memo[1] = 1
    memo[2] = 3
    for i in range(3, N + 1):
        memo[i] = memo[i-1] + 2*memo[i-2]
    
    return memo[N]

print(dp(N) % 10007)