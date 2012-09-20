# Problem 62
# 
# The cube, 41063625 (3453), can be permuted to produce two other cubes: 56623104 (3843) and 66430125 (4053). In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.
# 
# Find the smallest cube for which exactly five permutations of its digits are cube.
#

import sys

x = 0
mydict = dict()
while 1:
    working_value = x*x*x
    working_key = ''.join(sorted(str(working_value)))
    if working_key in mydict:
        new_list = mydict[working_key][1]
        new_list.append(working_value)
        mydict[working_key] = (mydict[working_key][0]+1,new_list)
    else:
        mydict[working_key] = (1, [working_value])

    if(mydict[working_key][0] == 5):
        print mydict[working_key][1][0]
        sys.exit(0)

    x+=1

