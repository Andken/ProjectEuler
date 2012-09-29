# Problem 69

N = 10

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

count_of_relativel_primes = [0]*N


for p in primes(N):
    i = p
    while i < N:
        count_of_relativel_primes[i] += 1
        i += p




print count_of_relativel_primes
