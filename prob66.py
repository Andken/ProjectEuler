# Problem 66

import math

def is_square(n):
    return math.sqrt(n).is_integer()

def is_square2(n):
    h = n & 0xF
    if h > 0x9:
        return False;
    if (not h == 0x2 and
        not h == 0x3 and
        not h == 0x5 and
        not h == 0x6 and
        not h == 0x7 and
        not h == 0x8):
        return math.sqrt(n).is_integer()
    return False

def is_square3(n):
    root_n = 0
    while(root_n * root_n < n):
        root_n = root_n+1
    return root_n*root_n == n

def is_square4(n):
    h = n & 0x3f

    if(not h == 0x00 and
       not h == 0x01 and
       not h == 0x04 and
       not h == 0x09 and
       not h == 0x10 and
       not h == 0x11 and
       not h == 0x19 and
       not h == 0x21 and
       not h == 0x24 and
       not h == 0x29 and
       not h == 0x31 and
       not h == 0x39):
        return False
    else:
        s = int(math.sqrt(n));
        return s**2 == n;


max_minimal_x = -1
max_minimal_D = -1

for D in range(75):
#for D in range(1001):
    if not is_square(D):        
        y = 1
        x_squared = D*(y**2) + 1
        while (not is_square(x_squared)):
            x_squared = D*(y**2) + 1
            y = y+1
        x = math.sqrt(x_squared)
        if x > max_minimal_x:
            max_minimal_x = x
            max_minimal_D = D
            print max_minimal_x, max_minimal_D




