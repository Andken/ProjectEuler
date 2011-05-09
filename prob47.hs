-- Prob 47
-- The first two consecutive numbers to have two distinct prime factors are:
-- 
-- 14 = 2  7
-- 15 = 3  5
-- 
-- The first three consecutive numbers to have three distinct prime factors are:
-- 
-- 644 = 2²  7  23
-- 645 = 3  5  43
-- 646 = 2  17  19.
-- 
-- Find the first four consecutive integers to have four distinct primes factors. What is the first of these numbers?

module Prob47
    where
      import Data.List (group)
      import Data.List

      factor n (p:ps) 
          | p*p > n        = [n]
          | n `mod` p == 0 = p : factor (n `div` p) (p:ps)
          | otherwise      = factor n ps

      primes = 2 : filter ((==1) . length . primeFactors) [3,5..]
      primeFactors n = factor n primes
      uniquePF n = Data.List.nub (primeFactors n)
--      get_five y = zip y (zip (tail y) (zip (tail (tail y)) (zip (tail(tail(tail y))) (tail(tail (tail (tail y)))))))          
      get_four y = zip (tail y) (zip (tail(tail y)) (zip (tail(tail(tail y))) (tail(tail(tail(tail y))))))
      matches x = not((fst(x) == 4) && (fst(snd(x)) == 4) && (fst(snd(snd(x))) == 4) && (snd(snd(snd(x))) == 4))
      answer = length(takeWhile (matches) (get_four (map length (map uniquePF [1..])))) + 2





