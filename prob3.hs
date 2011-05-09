--The prime factors of 13195 are 5, 7, 13 and 29.
--
--What is the largest prime factor of the number 600851475143 ?

module Prob3
    where
      number = 600851475143
--      number = 13195

      largest x = 
           if (x `div` smallest x) == 1
           then x
           else
               largest (x `div` smallest x)

      smallest 1 = 1
      smallest y = 
          if even y
          then 2
          else
              fromIntegral(last(takeWhile ((\x -> (y `rem` x > 0) && (x<y))) [2..]) + 1)
          
      answer = largest number


