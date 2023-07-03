N, M = map(int, input().split())

arr = [[0 for j in range(M)] for i in range(N)]

for i in range(0, N):
    str = list(input())
    for j in range(0, M):
        arr[i][j] = str[j]

length = 0

for _ in range(0, 50):
    for i in range(0, N):
        for j in range(0, M):
            if i + _ < N and j + _ < M:
                if arr[i][j] == arr[i + _][j] and arr[i][j] == arr[i][j + _] and arr[i][j] == arr[i + _][j + _]:
                    length = _

print((length + 1) * (length + 1))
