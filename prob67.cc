// Prob 67
// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
// 
// 3
// 7 4
// 2 4 6
// 8 5 9 3
// 
// That is, 3 + 7 + 4 + 9 = 23.
// 
// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
// 
// NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o) 
// 

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
  vector<vector<int> > v = readFile("prob67.txt");
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
