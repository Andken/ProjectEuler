--By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
--
--What is the 10001st prime number?
module Prob7
    where
      number = 10000 -- index starts at 0

      primes :: [Integer]
      primes = sieve [2..]
          where
            sieve (p:xs) = p : sieve [x | x<-xs, x `mod` p /= 0] 
                           
      answer = primes !! number