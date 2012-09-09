# Problem 60
# The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime. The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.
# 
# Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.
# 

MAX_NUM = 10000000

def generatePrimesFrom3(n):
    primes = [3]
    for i in range(5,n,2):
        for j in primes:
            if i%j == 0:
                break

            if j*j > i:
                primes.append(i)
                break

    return primes

def concatInts(a,b):
    temp = str(a) + str(b)
    return int(temp)

def numberLength(a):
    return len(str(a))

primes = generatePrimesFrom3(MAX_NUM)
fastLookup = set(primes)
pairs = []

print "Generated primes"

max_number_length = (len(str(MAX_NUM))/2)


max_index = 0
while(len(str(primes[max_index])) <= max_number_length):
    max_index += 1

for i in range(0, max_index):
    for j in range(i+1, max_index):
        if((concatInts(primes[i], primes[j]) in fastLookup) and
           (concatInts(primes[j], primes[i]) in fastLookup)):
            pairs.append((primes[i],primes[j]))
            
print "Made pairs"
#print len(pairs)
#print pairs
