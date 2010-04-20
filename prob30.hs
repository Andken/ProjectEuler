import Char

n = 5

sum_of_powers_matches_x x = x == sum_of_powers x

sum_of_powers x = sum(map (^n) (map (Char.digitToInt) (show(x))))

answer = sum (filter (sum_of_powers_matches_x) [2..1000000])
