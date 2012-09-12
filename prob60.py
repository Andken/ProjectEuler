# Problem 60
# The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
# 
# Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
# 

MAX_NUM = 20000

def isPrime(a, primes_list, primes_set):
    if a%2==0 and a!=2:
        return False 

    if a in primes_set:
        return True

    for i in primes_list:
        if a%i == 0:
            return False
        if i*i > a:
            return True

    # a is larger than the max sized prime in list squared
    working_max = primes[-1]
    # print "checking %d (working_max %d" % (a, working_max)
    while working_max*working_max < a:
        if a%working_max == 0:
            return False

        working_max += 2

    return True
    

def generatePrimesFrom3(n):
    primes = [3]
    for i in range(5,n,2):
        if isPrime(i, primes, set([])):
            primes.append(i)

    return primes

def concatInts(a,b):
    temp = str(a) + str(b)
    return int(temp)

def numberLength(a):
    return len(str(a))

primes = generatePrimesFrom3(MAX_NUM)
fastLookup = set(primes)
pairs = set([])

for i in range(0, len(primes)):
    for j in range(i+1, len(primes)):
        if(isPrime(concatInts(primes[i], primes[j]), primes, fastLookup) and
           isPrime(concatInts(primes[j], primes[i]), primes, fastLookup)): 
            pairs.add((primes[i],primes[j]))
            
#print len(pairs)
#print pairs



triplets = [(x[0],x[1],y[1]) for x in pairs for y in pairs if x[1] == y[0] and (x[0], y[1]) in pairs]
quads = [(x[0],x[1],x[2],y[2]) for x in triplets for y in triplets if (x[1] == y[0] and x[2] == y[1] and (x[0], y[2]) in pairs)]
quints = [(x[0],x[1],x[2],x[3],y[3]) for x in quads for y in quads if (x[1] == y[0] and x[2] == y[1] and x[3] == y[2] and (x[0], y[3]) in pairs)]
print quints

