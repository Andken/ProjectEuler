-- Problem 56

-- A googol (10100) is a massive number: one followed by one-hundred zeros; 100100 is almost unimaginably large: one followed by two-hundred zeros. Despite their size, the sum of the digits in each number is only 1.
-- 
-- Considering natural numbers of the form, ab, where a, b  100, what is the maximum digital sum?

import Char
digitalSum a b = sum(map digitToInt (show(a^b)))
maxDigitalSum x = maximum(map (digitalSum x) [1..100])
answer = maximum(map maxDigitalSum [1..100])
