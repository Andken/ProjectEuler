-- Prob 48
-- The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.
--
-- Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.


module Prob48
    where
      calc n = n^n
      working = (show(sum(map (calc) [1..1000])))
      answer = drop (length(working)-10) working
