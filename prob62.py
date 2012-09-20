# Problem 62
# 
# The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
# 
# Find the smallest cube for which exactly five permutations of its digits are cube.
#


def numDigits(a):
    return len(str(a))

def cube(x): return x*x*x

def isPermute(x,y):
    return sorted(str(x)) == sorted(str(y))


the_list = map(lambda x:x*x*x, range(10001))    


working_digits=0
working_list = []
for x in the_list:
    if(numDigits(x) > working_digits):
        saved_y = 0
        for y in working_list:
            num_permutes = 0
            for z in working_list:
                if not y == z:
                    if isPermute(y, z):
                        num_permutes = num_permutes + 1
            if num_permutes == 4:
                print y

        working_list = []
        working_digits = numDigits(x)
    
    working_list.append(x)
