--n! means n * (n * 1)  ...  3 * 2 * 1
--
--Find the sum of the digits in the number 100!

module Prob20
       where
         import Char

         answer = sum(map digitToInt (show(product [1..100])))
