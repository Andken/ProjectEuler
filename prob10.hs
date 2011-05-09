--The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
--
--Find the sum of all the primes below two million.

module Prob10
    where
      primes :: [Integer]
      primes = sieve [2..]
          where
            sieve (p:xs) = p : sieve [x | x<-xs, x `mod` p /= 0] 
                           
      number = 2000000

      answer = foldr (+) 0 (takeWhile (< number) primes)
