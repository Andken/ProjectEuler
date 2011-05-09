--A Pythagorean triplet is a set of three natural numbers, a  b  c, for which,
--
--a2 + b2 = c2
--For example, 32 + 42 = 9 + 16 = 25 = 52.
--
--There exists exactly one Pythagorean triplet for which a + b + c = 1000.
--Find the product abc.
--

module Prob9
    where

      -- a lot by paper
      -- a+b+c=1000 && a^2 + b^2 = c^2
      -- reduces to (500-a)/(1-a/1000) = b

      b::Float->Float
      b a = (500-a) / (1-(a / 1000))

      possible_as = map (b) [1..500]
      -- look for the case where there is a integer for the answer
      -- the answer is 375

      c = 1000 - ((b 375) + 375)
      answer = 375 * (b 375) * c
      