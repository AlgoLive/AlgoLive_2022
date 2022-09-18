import sys

(n, m, r) = map(int, sys.stdin.readline().split())  # 노드개수 / 수색 범위 / 길개수

arr = [[16] * (n + 1) for _ in range(n + 1)]  # 배열을 최대 수색 범위보다 큰 수로 초기화
itemNum = [16] + list(map(int, sys.stdin.readline().split()))  # 노드별 아이템 갯수 배열
ans = []  # 답의 후보군 배열

for _ in range(r):  # 입력 값을 통해 노드(그래프) 초기화
    (x, y, distance) = map(int, sys.stdin.readline().split())
    arr[x][y] = distance
    arr[y][x] = distance
for i in range(1, n + 1):  # 현재 노드 -> 같은 노드 거리는 0 취급
    arr[i][i] = 0


# 문제 풀이를 하며 콘솔창에 현재 그래프 상황을 프린트 해주는 함수 모듈화
def printarray(array):
    print("------------------------")
    for i in array:
        for j in i:
            if j == 16:
                print("   ", end='')
            else:
                print(f"{j:>3}", end='')
        print()


# printarray(arr)

for k in range(1, n + 1):   #플로이드 워셜 알고리즘 활용 , k는 중간노드 i,j를 확인할 때 i,j -> j,k 의 가능성 확인
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if arr[i][k] < 16 and arr[k][j] < 16:
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])

# printarray(arr)

for i in range(1, n + 1):   #특정 노드를 선택했을 경우 그 노드로부터 다른노드들 까지의 거리(가능한 경우)가 m이하이면 아이템 획득
    itemBuffer = 0
    for j in range(1, n + 1):
        if arr[i][j] <= m:
            itemBuffer += itemNum[j]    #모을 수 있는 아이템들을 더하여 저장
    ans.append(itemBuffer)  # 각각 노드를 선택한 경우 모을 수 있는 아이템들의 합 중 최대값이 정답

print(max(ans))

#플로이드 워셜 알고리즘은 n^3의 시간복잡돌를 가짐, n이 100이하이므로, 100^3 은 1억보다 작은 수 이므로 푸는데 지장없다고 판단하였음.
#하나의 노드로부터 최단거리가 아닌, 모든 노드에 대해 다른 노드까지의 최댄거리 모두가 필요하므로 본 알고리즘을 활용하였음
#접근할 수 없는 노드를 16으로 두었음. (16 이상의 수는 다룰 일이 없기 때문) 음수로 둘 경으 최솟값 비교시 귀찮은 점이 발생하여 이렇게 설정함
#일반적인 풀이들은 INF상수를 매우 큰 수로 활용하는것으로 보임.