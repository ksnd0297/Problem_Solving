#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int recur() {
    char c;
    int v, s, r;
    v = s = 0;

    scanf("%c", &c);
    if (c == '\n') return 0;
    if (c == '[' || c == '(') {
        if (c == '[') v = 3;
        else v = 2;
        while ((r = recur()) > 0) s += r;
        if (v + r) return -1;

        return v * (s == 0 ? 1 : s);
    }
    else
        if (c == ']') return -3;
        else return -2;
}
int main() {
    int s, r;
    s = r = 0;

    while ((r = recur()) > 0) s += r;

    printf("%d", r >= 0 ? s : 0);
    return 0;
}