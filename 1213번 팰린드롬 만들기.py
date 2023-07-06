str = input()

alphabet = [0] * 26

for _ in str:
    alphabet[ord(_) - ord("A")] += 1

EVEN_COUNT = 0

for i in range(0, len(alphabet)):
    if alphabet[i] % 2 != 0:
        EVEN_COUNT += 1

if len(str) % 2 != 0 and EVEN_COUNT != 1 or len(str) % 2 == 0 and EVEN_COUNT != 0:
    print("I'm Sorry Hansoo")
    exit()

ANSWER = ""
EVEN_ALPHA = ""

for _ in range(len(alphabet) - 1, -1, -1):
    while alphabet[_] != 0:
        if alphabet[_] == 1:
            EVEN_ALPHA = chr(_ + ord("A"))
            alphabet[_] -= 1
            break

        ANSWER = chr(_ + ord("A")) + ANSWER + chr(_ + ord("A"))
        alphabet[_] -= 2


if EVEN_ALPHA != "":
    A = ANSWER[0 : len(ANSWER) // 2]
    B = ANSWER[len(ANSWER) // 2 : len(ANSWER)]
    ANSWER = (
        ANSWER[0 : len(ANSWER) // 2]
        + EVEN_ALPHA
        + ANSWER[len(ANSWER) // 2 : len(ANSWER)]
    )

print(ANSWER)
