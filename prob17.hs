max = 1000

singleNum 1000 = (singleNum 1) + length("thousand")
singleNum 1 = length("one")
singleNum 2 = length("two")
singleNum 3 = length("three")
singleNum 4 = length("four")
singleNum 5 = length("five")
singleNum 6 = length("six")
singleNum 7 = length("seven")
singleNum 8 = length("eight")
singleNum 9 = length("nine")
singleNum n = 
	if n >=100 && n <= 999
	   then if((n `mod` 100) == 0)
	     	then (singleNum (n `div` 100)) + length("hundred")
	   else (singleNum (n `div` 100)) + length("hundred") + length("and") + (singleNum (n `mod` 100))
	else if n >=20 && n < 30
		then length("twenty") + (singleNum (n `mod` 10))
	else if n >=30 && n <= 39
		then length("thirty") + (singleNum (n `mod` 10))
	else if n >=40 && n <= 49
		then length("forty") + (singleNum (n `mod` 10))
	else if n >=50 && n <= 59
		then length("fifty") + (singleNum (n `mod` 10))
	else if n >=60 && n <= 69
		then length("sixty") + (singleNum (n `mod` 10))
	else if n >=70 && n <= 79
		then length("seventy") + (singleNum (n `mod` 10))
	else if n >=80 && n <= 89
		then length("eighty") + (singleNum (n `mod` 10))
	else if n >=90 && n <= 99
		then length("ninety") + (singleNum (n `mod` 10))
	else if n == 10
	     	then length("ten")
	else if n == 11
	     	then length("eleven")
	else if n == 12
	     	then length("twelve")
	else if n == 13
	     	then length("thirteen")
	else if n == 14
	     	then length("fourteen")
	else if n == 15
	     	then length("fifteen")
	else if n == 16
	     	then length("sixteen")
	else if n == 17
	     	then length("seventeen")
	else if n == 18
	     	then length("eighteen")
	else if n == 19
	     	then length("nineteen")
	else 0

answer = sum(map singleNum [1..1000])




