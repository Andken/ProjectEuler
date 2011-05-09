--The square of the sum of the first ten natural numbers is,
--
--(1 + 2 + ... + 10)2 = 552 = 3025
--Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025  385 = 2640.
--
--Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
module Prob6
    where
      number = 100

      sum_of_squares = foldr (+) 0 (map (^2) [1..number])
      square_of_sum = (foldr (+) 0 [1..number])^2
      answer = square_of_sum - sum_of_squares

