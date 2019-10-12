#include "Rational.h"


	int n{ 0 };
	int m{ 1 };

	Rational::Rational() {};

	Rational:: Rational(int m1) {
		m = m1;
	};
	Rational::Rational(const int m1, const int n1) {
		m = m1 / NOD(n1, m1);
		n = n1 / NOD(n1, m1);
		if (n < 0) {
			m *= -1;
			n *= -1;
		}
	};

	 bool Rational::operator==(const Rational& rhs) {
		return (m == rhs.m) && (n == rhs.n);
	}
	
	bool Rational::operator!=(const Rational& rhs) {
		return !operator==(rhs);
	}
	bool Rational::operator>(const Rational& rhs) {
		return ((*this - rhs).m > 0);
	}
	bool Rational::operator>=(const Rational& rhs) {
		return (*this - rhs).m >= 0;
	}
	bool Rational::operator<(const Rational& rhs) {
		return !operator>=(rhs);
	}
	bool Rational::operator<=(const Rational& rhs) {
		return !operator>(rhs);
	}


inline ostream& operator<<(ostream& ostrm, const Rational& rhs) {
	return rhs.writeTo(ostrm);
}
inline istream& operator>>(istream& istrm, Rational& rhs) {
	return rhs.readFrom(istrm);
}
int NOD(int n1, int n2)
{
	n1 = abs(n1);
	n2 = abs(n2);
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
	n1 = abs(n1);
	n2 = abs(n2);
	return n1 * n2 / NOD(n1, n2);
}
Rational Rational::operator-(const Rational& rhs) {
	int k = NOK(n, rhs.n);
	return Rational((m * k / n) - (rhs.m * k / rhs.n), k);
}
Rational& Rational::operator+=(const Rational& rhs) {
	int k = NOK(n, rhs.n);
	m = n / k + rhs.n / k;
	n = k;
	return *this;
}
Rational& Rational::operator-=(const Rational& rhs) {
	int k = NOK(n, rhs.n);
	m = n / k - rhs.n / k;
	n = k;
	return *this;
}
Rational& Rational::operator*=(const Rational& rhs) {
	m *= rhs.m;
	n *= rhs.n;
	int k = NOD(m, n);
	m /= k;
	n /= k;
	return *this;
}
Rational& Rational::operator/=(const Rational& rhs) {
	m *= rhs.n;
	n *= rhs.m;
	int k = NOD(m, n);
	m /= k;
	n /= k;
	if (n < 0) {
		n *= -1;
		m *= -1;
	}
	return *this;
}
Rational operator+(const Rational& lhs, const Rational& rhs) {
	int k = NOK(lhs.n, rhs.n);
	return Rational((lhs.m * k / lhs.n) + (rhs.m * k / rhs.n), k);
}
Rational operator*(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.m * rhs.m, lhs.n * rhs.n);
}
Rational operator/(const Rational& lhs, const Rational& rhs) {
	return Rational(lhs.m / rhs.n, lhs.n * rhs.m);
}
ostream& Rational::writeTo(ostream& ostrm) const {
	ostrm << m << "/" << n;
	return ostrm;
}
istream& Rational::readFrom(istream& istrm) {
	char sep;
	int m1, n1;
	istrm >> m1 >> sep >> n1;
	Rational temp(m1, n1);
	m = temp.m;
	n = temp.n;
	return istrm;
}