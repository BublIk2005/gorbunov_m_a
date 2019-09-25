#include<iostream>

using namespace std;

struct Rational
{
	int m{ 0 };
	int n{ 1 };
	Rational();
	int NOD(int n1, int n2)
	{
		int div;
		if (n1 == n2)  return n1;
		int d = n1 - n2;
		if (d < 0) {
			d = -d;  div = NOD(n1, d);
		}
		else
			div = NOD(n2, d);
		return div;
	}
	int NOK(int n1, int n2)
	{
		return n1 * n2 / NOD(n1, n2);
	}
	
	explicit Rational(const int a)
	{
		m = a;
	}
	Rational(const int a,const int b)
	{
		m = a/ NOD(a, b);
		n = b/ NOD(a, b);
		if (n < 0)
		{
			n *= -1;
			m *= -1;
		}
	}

	bool operator==(const Rational& rat)
	{
		return ((Rational(m, n) - rat)==Rational(0));
	}
	
	bool operator!=(const Rational& rat)
	{
		return (Rational(m, n) != rat);
	}
	
	Rational& operator +=(const Rational& r)
	{
		int k = NOK(n, r.n);
		m = (m * k / n) + (r.m * k / r.n);
		n = k;
		return *this;
	}
	Rational operator +(const Rational& r)
	{
		int k = NOK(n, r.n);
		return Rational((m * k / n) + (r.m * k / r.n), k);
	}
	Rational& operator -=(const Rational& r)
	{
		int k = NOK(n, r.n);
		m = (m * k / n) - (r.m * k / r.n);
		n = k;
		return *this;
	}
	Rational operator -(const Rational& r)
	{
		int k = NOK(n, r.n);
		return Rational((m * k / n) - (r.m * k / r.n), k);
	}
	Rational operator *(const Rational r)
	{
		return Rational(m*r.m, n*r.n);
	}
	
	Rational operator /(const Rational r)
	{
		return Rational(m*r.n, n*r.m);
	}
	Rational operator /=(const Rational r)
	{
		m = m * r.n;
		n = n * r.m;
		int k = NOD(m, n);
		m /= k;
		n /= k;
		return *this;
	}
	Rational operator *=(const Rational r)
	{
		m = m * r.n;
		n = n * r.m;
		int k = NOD(m, n);
		m /= k;
		n /= k;
		return *this;
	}
	bool operator>(const Rational r)
	{
		return((Rational(m, n) - r).n > 0);
	}
	bool operator<(const Rational r)
	{
		return((Rational(m, n) - r).n < 0);
	}
	bool operator>=(const Rational r)
	{
		return((Rational(m, n) - r).n >= 0);
	}
	bool operator<=(const Rational r)
	{
		return((Rational(m, n) - r).n >= 0);
	}
	ostream& WriteFrom(ostream ostrm)
	{
		ostrm << n << '/' << m;
		return ostrm;
	}
	istream& ReadFrom(istream istrm)
	{
		char separator{ '/' };
		istrm >> m >> separator >> n;
	}
	ostream& writeTo(std::ostream& ostrm) const
	{

	};
	istream& readFrom(std::istream& istrm);
	};
	inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
		 {
		 return rhs.writeTo(ostrm);
		 }
	
		 inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
		 {
		 return rhs.readFrom(istrm);
		 }
int main()
{
	Rational r(1,2);
	cout << r;
}