-- Problem 52
-- It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.
-- 
-- Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

import List
import Char
digitMatch a (b:bs) = sort(map digitToInt (show a)) == sort(map digitToInt (show b))
digitMatch a [] = True

isMatch [] = True
isMatch (x:xs) = digitMatch x xs && isMatch xs
result n = isMatch (map (n*) [2..6])
answer = head(take 1 (filter (result) [1..]))
