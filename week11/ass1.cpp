#include <iostream>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int abs(int a) {
	return a < 0 ? -a : a;
}

class Rational {
	friend std::ostream& operator<<(std::ostream& out, const Rational& ra);
public:
	Rational():numerator(1), denominator(1), mode(fraction) { };
	Rational(int n, int r): numerator(n), denominator(r), mode(fraction) {
		reduction();
	}
	Rational operator-() const;
	Rational plus(const Rational& ra);
	Rational minus(const Rational& ra) { return plus(-ra); }
	Rational multiply(const Rational& ra);
	Rational divide(const Rational& ra) { return multiply(Rational(ra.denominator, ra.numerator)); }
	Rational operator+(const Rational& ra) { return plus(ra); }
	Rational operator-(const Rational& ra) { return minus(ra); }
	Rational operator*(const Rational& ra) { return multiply(ra); }
	Rational operator/(const Rational& ra) { return divide(ra); }
	enum Mode{ fraction, decimal };
	void setMode(Mode m) { mode = m; }
private:
	int numerator, denominator;
	Rational reduction();
	Mode mode;
};

Rational Rational::reduction() {
	int temp = gcd(numerator, denominator);
	temp = abs(temp);
	numerator /= temp;
	denominator /= temp;
	return *this;
}

Rational Rational::operator-() const {
	Rational newRa;
	newRa.numerator = -numerator;
	newRa.denominator = denominator;
	return newRa;
}

Rational Rational::plus(const Rational& ra) {
	Rational newRa;
	newRa.denominator = ra.denominator * denominator;
	newRa.numerator = numerator * ra.denominator + ra.numerator * denominator;
	return newRa.reduction();
}

Rational Rational::multiply(const Rational& ra) {
	Rational newRa;
	newRa.denominator = ra.denominator * denominator;
	newRa.numerator = ra.numerator * numerator;
	return newRa.reduction();
}

std::ostream& operator<<(std::ostream& out, const Rational& ra) {
	if(ra.mode == Rational::fraction)
		out << ra.numerator << "/" << ra.denominator;
	else
		out << float(ra.numerator) / ra.denominator;
	return out;
}

int main() {
	using namespace std;
	Rational r1(1, 3);
	Rational r2(2, 3);
	cout << r1 + r2 << endl << r1 - r2 << endl << r1 * r2 << endl << r1 / r2 << endl;
	r1.setMode(Rational::decimal);
	r2.setMode(Rational::decimal);
	cout << r1 << endl << r2 << endl;
	return 0;
}
