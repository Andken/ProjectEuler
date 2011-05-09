-- Problem 34
-- 145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.
-- 
-- Find the sum of all numbers which are equal to the sum of the factorial of their digits.
-- 
-- Note: as 1! = 1 and 2! = 2 are not sums they are not included.

import Char
factorialSum [] = 0
factorialSum (x:xs) = factorial (digitToInt(x)) + factorialSum xs

factorial 0 = 1
factorial 1 = 1
factorial x = x * (factorial (x-1))

works x = x == factorialSum (show(x))

-- already found out that 40585 is the max
answer = sum(filter works [10..40586])

