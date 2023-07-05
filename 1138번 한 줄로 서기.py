N = int(input())
info = list(map(int, input().split()))

answer = [0 for i in range(N)]

for i in range(0, N):
    count = 0
    
    for _ in range(0, N):    
        if(count == info[i]):        
            while(answer[_] != 0):
                _ += 1

            answer[_] = i + 1
            break
          
        if(answer[_] == 0):
            count += 1        
    
        

for _ in answer:
    print(_, end = ' ')