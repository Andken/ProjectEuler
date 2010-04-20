-- Prob 21
-- Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
-- If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
-- 
-- For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
-- 
-- Evaluate the sum of all the amicable numbers under 10000.

module Prob21
    where
      
      divisors x = filter (evenlyDivisible x) [1..(x `div` 2)]

      evenlyDivisible x y = x `rem` y == 0

      isAmicable x = 
          let y = sum (divisors x)
          in x == sum (divisors y) && x /= y
                    

      answer = sum (filter (isAmicable) [1..10000])