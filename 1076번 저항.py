resistance = {
    'black':  0,
    'brown':  1,
    'red':    2,
    'orange': 3,
    'yellow': 4,
    'green':  5,
    'blue':   6,
    'violet': 7,
    'grey':   8,
    'white':  9,
}


color1 = input()
color2 = input()
color3 = input()

print((resistance[color1] * 10 + resistance[color2]) * (10 **resistance[color3]))