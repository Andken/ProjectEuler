-- prob 46

-- It was proposed by Christian Goldbach that every odd composite number can be written as the sum of a prime and twice a square.
-- 
-- 9 = 7 + 212
-- 15 = 7 + 222
-- 21 = 3 + 232
-- 25 = 7 + 232
-- 27 = 19 + 222
-- 33 = 31 + 212
-- It turns out that the conjecture was false.
-- 
-- What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?


module Prob46
    where
      import Data.List ((\\))

      primes :: [Integer]
      primes = sieve [3..]
          where
            sieve (p:xs) = p : sieve [x | x<-xs, x `mod` p /= 0] 
                           
                           --[1,3..] \\ primes
      


