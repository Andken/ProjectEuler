// Prob 43
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long unsigned int LLUINT;
typedef unsigned int UINT;

LLUINT toLLUINT(const string &num)
{
	LLUINT x;
	istringstream(num) >> x;
	return x;
}

string toString(UINT n)
{
	string s;
	stringstream out;
	out << n;
	s = out.str();

	if(s.length() == 2)
		{
			s.insert(0, "0");
		}

	return s;
}

UINT nextNum(UINT first_digit, const string &working_pandigital_number)
{
	string fd = toString(first_digit);
	string new_pd = fd+working_pandigital_number;
	UINT numb;
	istringstream(new_pd.substr(0, 3)) >> numb;
	return numb;
}

bool isSuitable(UINT n, const string &working_pandigital_number)
{
	string running_working_pandigital_number_copy(working_pandigital_number);
	const string s = toString(n);
	const int original_length = running_working_pandigital_number_copy.length();
	
	for(string::const_iterator it=s.begin(); it!=s.end(); ++it)
		{
			running_working_pandigital_number_copy.push_back(*it);
		}

	sort(running_working_pandigital_number_copy.begin(), running_working_pandigital_number_copy.end());
	string::iterator new_end = unique(running_working_pandigital_number_copy.begin(), running_working_pandigital_number_copy.end());
	
	running_working_pandigital_number_copy.erase(new_end, running_working_pandigital_number_copy.end());

	return running_working_pandigital_number_copy.length() == (original_length + s.length());
}

string addLastDigit(const string &num)
{
	string digits="0123456789";

	for(string::const_iterator i = num.begin();
		i!=num.end();
		++i)
		{
			for(string::iterator j = digits.begin();
				j!=digits.end();
				++j)
				{
					if(*j==*i)
						{
							digits.erase(j);
							break;
						}
				}
		}

	string new_num(num);
	new_num.insert(0, digits);
	return new_num;
}

void outputPandigitals(const vector<string> &wp)
{
	printf("######################\n");
	for(vector<string>::const_iterator working_pandigital_number=wp.begin();
		working_pandigital_number!=wp.end();
		++working_pandigital_number)
		{
			printf("\t%s\n", (*working_pandigital_number).c_str());
		}
}

int main()
{
	vector<string> working_pandigitals;
	vector<UINT> divisors;
	divisors.push_back(13);
	divisors.push_back(11);
	divisors.push_back(7);
	divisors.push_back(5);
	divisors.push_back(3);
	divisors.push_back(2);

	for(UINT i=17; i < 1000; i+=17)
		{
			string working_pandigital_number("");
			if(isSuitable(i, working_pandigital_number))
				{	
					const string s17(toString(i));
					for(string::const_iterator it = s17.begin(); it != s17.end(); ++it)
						{
							working_pandigital_number.push_back(*it);
						}
					working_pandigitals.push_back(working_pandigital_number);
				}
		}

	for(vector<UINT>::const_iterator divisor=divisors.begin(); divisor!=divisors.end(); ++divisor)
		{
			vector<string> new_working_pandigitals;
			for(vector<string>::const_iterator working_pandigital_number=working_pandigitals.begin(); 
				working_pandigital_number!=working_pandigitals.end(); 
				++working_pandigital_number)
				{
					for(UINT i=0; i<10; ++i)
						{
							string temp_working_pandigital_number(*working_pandigital_number);
							UINT new_num = nextNum(i, temp_working_pandigital_number);
							//							printf("i: %d nn: %d divisor: %d\n", i, new_num, *divisor);
							if((new_num%(*divisor) == 0) && isSuitable(i, temp_working_pandigital_number))
								{
									//									printf("\t\tbefore twpn: %s\n", temp_working_pandigital_number.c_str());
									temp_working_pandigital_number.insert(0, toString(i));
									//									printf("\t\tafter  twpn: %s\n", temp_working_pandigital_number.c_str());
									new_working_pandigitals.push_back(temp_working_pandigital_number);
								}
						}
				}
			working_pandigitals = new_working_pandigitals;
		}

	LLUINT result(0);
	for(vector<string>::const_iterator working_pandigital_number=working_pandigitals.begin();
		working_pandigital_number!=working_pandigitals.end();
		++working_pandigital_number)
		{
			result += toLLUINT(addLastDigit(*working_pandigital_number));
		}


	printf("answer: %llu\n", result);
}
