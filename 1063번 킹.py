MIN = 1
MAX = 8

king, stone, N = input().split()

# A 1
dir = {
    "R":  ( 1,   0), # 한 칸 오른쪽으로
    "L":  (-1,   0), # 한 칸 왼쪽으로
    "B":  ( 0,  -1), # 한 칸 아래로
    "T":  ( 0,   1), # 한 칸 위로
    "RT": ( 1,   1), # 오른쪽 위 대각선으로
    "LT": (-1,   1), # 왼쪽 위 대각선으로
    "RB": ( 1,  -1), # 오른쪽 아래 대각선으로
    "LB": (-1,  -1), # 왼쪽 아래 대각선으로

}

# 체스말이 밖에 있을 경우 0 안에 있을 경우 1 리턴
def isIn(piece):
    if(piece[0] < MIN or piece[0] > MAX or piece[1] < MIN or piece[1] > MAX):
        return 0
    else:
        return 1

stone = [ord(stone[0]) - ord('A') + 1, int(stone[1])]
king = [ord(king[0]) - ord('A') + 1, int(king[1])]

for _ in range(int(N)):
    ope = input()
    move = dir.get(ope) # 킹이 움직일 경로

    moveKing = [king[0] + move[0], king[1] + move[1]] # 움직인 킹의 자리

    if(moveKing[0] == stone[0] and moveKing[1] == stone[1]): # 킹이 움직이는 곳에 돌이 있을 경우
        moveStone = [stone[0] + move[0], stone[1] + move[1]] #움직인 돌의 자리
        if(not isIn(moveStone)):
            continue
        else:
            stone = moveStone

    if(not isIn(moveKing)):
        continue
    else:
        king = moveKing

print(chr(king[0] + ord('A') - 1) + chr(king[1] + ord('0')))
print(chr(stone[0] + ord('A') - 1) + chr(stone[1] + ord('0')))

  
    
    