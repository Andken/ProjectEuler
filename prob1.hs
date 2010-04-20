--If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
--
--Find the sum of all the multiples of 3 or 5 below 1000.

module Prob1
       where

l = [1..999]
fizzbuzz x =
    if mod x 5 == 0 || mod x 3 == 0
    then x
    else 0
answer = foldr (+) 0 (map (fizzbuzz) l)