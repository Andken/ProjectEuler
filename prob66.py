# Problem 66

import math

def is_square(n):
    return math.sqrt(n).is_integer()


max_minimal_x = 0
max_minimal_D = 0

for D in range(1001):
    if not is_square(D):        
        print D

