// 
// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// 
// That is, 3 + 7 + 4 + 9 = 23.
// 
// Find the maximum total from top to bottom of the triangle below:
// 
// 75
// 95 64
// 17 47 82
// 18 35 87 10
// 20 04 82 47 65
// 19 01 23 75 03 34
// 88 02 77 73 07 63 67
// 99 65 04 28 06 16 70 92
// 41 41 26 56 83 40 80 70 33
// 41 48 72 33 47 32 37 16 94 29
// 53 71 44 65 25 43 91 52 97 51 14
// 70 11 33 28 77 73 17 78 39 68 17 57
// 91 71 52 38 17 14 91 43 58 50 27 29 48
// 63 66 04 68 89 53 67 30 73 16 69 87 40 31
// 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
// 
// NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
 


#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdlib.h>
using namespace std;


vector<vector<int> > readFile(const string &filename)
{
  vector<vector <int> >v;
  ifstream in(filename.c_str());
  if(!in)
    {
      cerr << "Cannot open " << filename << endl;
      return v;
    }
  while(in)
    {
      vector <int> x;
      char str[65536];
      in.getline(str, 65536);      // Delimiter defaults to newline
      char * pch;
      pch = strtok (str," ");
      while (pch != NULL)
	{
	  x.push_back(atoi(pch));
	  pch = strtok (NULL, " ");
	}
      v.push_back(x);
    }

  in.close();
  return v;
}

void printTriangle(const vector<vector<int> > &v)
{
  for(vector<vector <int> >::const_iterator i = v.begin();
      i != v.end();
      ++i)
    {
      for(vector<int>::const_iterator j = (*i).begin();
	  j != (*i).end();
	  ++j)
	{
	  cout << *j << " ";
	}
      cout << endl;
    }
}

inline int max(int x, int y)
{
  return x > y ? x : y;
}

int main()
{
  vector<vector<int> > v = readFile("prob18.txt");
  printTriangle(v);

  const int num_iterations = v.size()-1;
  //  cout << "num_iterations: " << num_iterations << endl;
  for(int i=num_iterations-2; i>=0; --i)
    {
      //      cout << "i: " << i << endl;
      const vector<int> working = v.at(i);
      vector<int> replacement;
      for(unsigned int j=0; j<working.size(); ++j)
	{
	  //	  cout << "\tj: " << j << endl; 
	  //	  cout << "\t\tworking[j]: " << working.at(j) << endl;
	  //	  cout << "\t\v.at(i+1).at(j): " << v.at(i+1).at(j) << endl;
	  //	  cout << "\t\v.at(i+1).at(j+1): " << v.at(i+1).at(j+1) << endl;
	  replacement.push_back(working.at(j)+max(v.at(i+1).at(j),
						  v.at(i+1).at(j+1))); 
	}
      v[i] = replacement;
      //      printTriangle(v);
    }
  cout << v.at(0).at(0) << endl;
  return 0;
}
