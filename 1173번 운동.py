from sys import exit

N, m, M, T, R = map(int, input().split())

TOTAL_TIME = 0

EXERCISE_TIME = 0
health = m

if health + T > M:
    print(-1)
    exit()


while EXERCISE_TIME != N:
    if health + T <= M:
        health += T
        EXERCISE_TIME += 1
        TOTAL_TIME += 1

    elif health + T > M:
        health -= R
        if health < m:
            health = m
        TOTAL_TIME += 1

print(TOTAL_TIME)
