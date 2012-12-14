
#include <list>
#include <stdio.h>


static const int MAX_D=1000000;

class Frac
{
private:
	int m_n;
	int m_d;

public:
    Frac(int n, int d) :
        m_n(n),
		m_d(d)
    {
	}
    
    bool IsProper() const
    {
        if(m_n>=m_d)
			return 0;
        
		
        int x=m_d;
        int y=m_n;
		while(x != y)
			{
				if(x>y)
					x-=y;
				else
					y-=x;
			}

        return x == 1;
	}

    void Print() const
	{
        printf("%d/%d\n", m_n, m_d);
	}

	float value() const
	{
		return m_n/float(m_d);
	}

	bool operator<(const Frac &other)
	{
		return value() < other.value();
	}

};

int main()
{
	using namespace::std;

	list<Frac> l;

	int d=MAX_D;

	Frac current(2,5);

	while(d>1)
		{
			int n=(d*3/float(7))-1;
			while(n/float(d) < 3/float(7))
				{
					if(n>0)
						{
							Frac f(n,d);
							if(f.IsProper())
								{
									if((n!=3 && d!=7) && current<f)
										{
											current=f;
										}
								}
						}

					++n;
				}
			--d;
		}
	
	current.Print();		

	return 0;
}	

