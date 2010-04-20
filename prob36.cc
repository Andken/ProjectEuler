// The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.
// 
// Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
// 
// (Please note that the palindromic number, in either base, may not include leading zeros.)

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

inline string reverse(const string &src) 
{ 
  return string(src.rbegin(), src.rend()); 
}

inline bool isPalindrome(const string &s)
{
  return s == reverse(s);
}

inline bool isDecimalPalindrome(const unsigned int x)
{
  ostringstream strstrm;
  strstrm << x;
  return isPalindrome(strstrm.str());
}

inline string binaryDigit(const char c)
{
  switch(c)
    {
    case '0':
      return "0000";
    case '1':
      return	"0001";
    case '2':
      return	"0010";
    case '3':
      return	"0011";
    case '4':
      return	"0100";
    case '5':
      return	"0101";
    case '6':
      return	"0110";
    case '7':
      return	"0111";
    case '8':
      return	"1000";
    case '9':
      return	"1001";
    case 'A':
    case 'a':
      return	"1010";
    case 'B':
    case 'b':
      return	"1011";
    case 'C':
    case 'c':
      return	"1100";
    case 'D':
    case 'd':
      return	"1101";
    case 'E':
    case 'e':
      return	"1110";
    case 'F':
    case 'f':
      return	"1111";
    default:
      cerr << "WRONG: " << c << endl;
      return "";
    }
}


inline string binaryString(const unsigned int x)
{
  ostringstream hex_strstrm;
  hex_strstrm << hex << x;
  
  string output;
  for(unsigned int i=0; i<hex_strstrm.str().length(); ++i)
    {
      char working = hex_strstrm.str()[i];
      output += binaryDigit(working);
    }
  
  // trim leading zeros
  while(output[0] == '0')
    {
      output = output.erase(0,1);
    }
  
  return output;
}

inline bool isBinaryPalindrome(const unsigned int x)
{
  return isPalindrome(binaryString(x));
}

int main()
{
  //	cout << isDecimalPalindrome(585) << endl;
  //	cout << isBinaryPalindrome(585) << endl;
  //	cout << binaryString(585) << endl;
  //	return 0;
  
  int running_total = 0;
  for(int i=0; i<1000000; ++i)
    {
      if(isDecimalPalindrome(i) &&
	 isBinaryPalindrome(i))
	{
	  running_total += i;
	}
    }
  
  cout << "answer: " << running_total << endl;
  return 0;
}

