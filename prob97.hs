module Prob97
    where
	number = (28433*2^(7830457)) + 1
	answer = drop (length (show(number))-10) (show(number))
