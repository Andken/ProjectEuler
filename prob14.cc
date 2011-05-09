#include <iostream>
#include <list>

using namespace std;

const unsigned int MAX_BOUND = 1000000;

inline unsigned int nextNumber(unsigned int x)
{
  return (x%2 == 0) ? x/2 : ((3*x)+1);
}

inline size_t getSeqLength(const unsigned int x)
{
  size_t length = 0;

  for(unsigned int y=x; y != 1; y=nextNumber(y))
    {
      ++length;
    }

  // +1 for the 1 on the end
  return length + 1;
}

int main()
{
  size_t current_max = 0;
  unsigned int current = 0;

  for(int i=MAX_BOUND; i>0; --i)
    {
       size_t sl = getSeqLength(i);

      if(sl > current_max)
	{
	  current = i;
	  current_max = sl;
	}
    }

  cout << "answer: " << current << endl;
  
  return 0;
}



#if 0
void printList(const list<unsigned int> &v)
{
  for(list<unsigned int>::const_iterator i = v.begin();
      i != v.end();
      ++i)
    cout << *i << ", ";
  cout << endl;
}

inline unsigned int nextNumber(unsigned int x)
{
  return (x%2 == 0) ? x/2 : ((3*x)+1);
}

inline size_t checkValueAndRemoveSequenceFromList(list<unsigned int> &v)
{
  size_t length = 0;

  for(unsigned int y=v.front(); y != 1; y=nextNumber(y))
    {
      ++length;
      if(y%2 == 1 && y < MAX_BOUND)
	{
	  v.remove(y);
	}
    }

  // +1 for the 1 on the end
  return length + 1;
}

int main()
{
  // create the working list

  list<unsigned int> v;
  for(unsigned int i=3; i<=MAX_BOUND; i+=2)
    {
      v.push_front(i);
    }

  unsigned int current_start = -1;
  unsigned int current_max = 0;
  while(v.size() > 1)
    {
      const unsigned int working = v.front();
      const size_t length = checkValueAndRemoveSequenceFromList(v);
      if(length > current_max)
	{
	  current_start = working;
	  current_max = length;
	}
    }

  cout << "answer: " << current_start << ":(";
  cout << current_max << ")" << endl;


  return 0;
}
#endif
