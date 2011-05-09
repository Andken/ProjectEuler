--2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
--
--What is the smallest number that is evenly divisible by all of the numbers from 1 to 20?
module Prob5
    where
      number = 20

      isNotEvenlyDivided x = length(filter (== 0) (map (x `mod`) [1..number])) /= number

      answer = last(takeWhile (isNotEvenlyDivided) (map (number *) [1..])) + number
    
      -- others that are sort of cheating, but they're faster
      answer2 = foldr (lcm) 1 [2..number]
      answer3 = 2*3*2*5*7*2*3*11*13*2*17*19
