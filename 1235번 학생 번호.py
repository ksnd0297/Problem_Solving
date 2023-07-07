N = int(input())

arr = []

MAX_LENGTH = 0

for _ in range(N):
    str = input()
    arr.append(str)
    MAX_LENGTH = max(MAX_LENGTH, len(str))

for _ in range(1, MAX_LENGTH + 1):
    FLAG = False
    for i in range(0, N):
        for j in range(i + 1, N):
            if arr[i][-_:] == arr[j][-_:]:
                FLAG = True

    if not FLAG:
        print(_)
        exit()
