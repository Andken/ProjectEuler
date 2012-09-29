# Problem 69

N = 1000000

def primes(n):
    s=range(0,n+1)
    s[1]=0
    bottom=2
    top=n//bottom
    while (bottom*bottom<=n):
        while (bottom<=top):
            if s[top]:
                s[top*bottom]=0
            top-=1
        bottom+=1
        top=n//bottom
    return [x for x in s if x]


p = primes(N)

i = 0
num = p[i]
while num < N:
    i += 1
    num *= p[i]
    if(num < N):
        print num
