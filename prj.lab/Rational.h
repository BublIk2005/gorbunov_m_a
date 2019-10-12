#include <iostream>
#include <sstream>


using namespace std;

int NOD(int n1, int n2);
int NOK(int n1, int n2);

struct Rational {
	int n;
	int m;

	Rational() ;

	explicit Rational(int m1);
	Rational(const int m1, const int n1);

	Rational operator-(const Rational& rhs);
	Rational& operator+=(const Rational& rhs);
	Rational& operator-=(const Rational& rhs);
	Rational& operator*=(const Rational& rhs);
	Rational& operator/=(const Rational& rhs);
	bool operator==(const Rational& rhs);
	bool operator!=(const Rational& rhs);
	bool operator>(const Rational& rhs);
	bool operator>=(const Rational& rhs);
	bool operator<(const Rational& rhs);
	bool operator<=(const Rational& rhs);

	ostream& writeTo(ostream& ostrm) const;
	istream& readFrom(istream& istrm);

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const Rational& rhs);

inline ostream& operator<<(ostream& ostrm, const Rational& rhs);
inline istream& operator>>(istream& istrm, Rational& rhs);