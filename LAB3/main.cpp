#include <iostream>

using namespace std;

// Rational Class declaration
class Rational {
   private:
      int numerator;
      int denominator; 
   public:
      Rational();
      explicit Rational(int); 
      Rational(int, int); 
      const Rational add(const Rational &) const; 
      const Rational subtract(const Rational &) const; 
      const Rational multiply(const Rational &) const; 
      const Rational divide(const Rational &) const;
      void simplify();
      void display() const;
	  int getNumerator() const;
	  int getDenominator() const;
   private:
      int gcd(int, int) const;
};

// Implement Rational class member functions here

Rational::Rational() {
	this->numerator = 0;
	this->denominator = 1;
}

Rational::Rational(int num) {
	this->numerator = num;
	this->denominator = 1;
}

Rational::Rational(int numerator, int denominator) {
	this->numerator = numerator;
	this->denominator = denominator;
}

const Rational Rational::add(const Rational &r) const {
	int num1 = this->numerator; // a
	int num2 = r.getNumerator(); // c
	int den1 = this->denominator; // b
	int den2 = r.getDenominator(); // d
	
	int newNum = num1 * den2 + den1 * num2;
	int newDen = den1 * den2;
	
	return Rational(newNum, newDen);
}

const Rational Rational::subtract(const Rational &r) const {
	int num1 = this->numerator; // a
	int num2 = r.getNumerator(); // c
	int den1 = this->denominator; // b
	int den2 = r.getDenominator(); // d
	
	int newNum = num1 * den2 - den1 * num2;
	int newDen = den1 * den2;
	
	return Rational(newNum, newDen);
}

const Rational Rational::multiply(const Rational &r) const {
	int num1 = this->numerator; // a
	int num2 = r.getNumerator(); // c
	int den1 = this->denominator; // b
	int den2 = r.getDenominator(); // d
	
	int newNum = num1 * num2;
	int newDen = den1 * den2;
	
	return Rational(newNum, newDen);
}

const Rational Rational::divide(const Rational &r) const {
	int num1 = this->numerator; // a
	int num2 = r.getNumerator(); // c
	int den1 = this->denominator; // b
	int den2 = r.getDenominator(); // d
	
	int newNum = num1 * den2;
	int newDen = den1 * num2;
	
	return Rational(newNum, newDen);
}

void Rational::simplify() {
	int gcd = this->gcd(this->numerator, this->denominator);
	this->numerator = this->numerator / gcd;
	this->denominator = this->denominator / gcd;
}

void Rational::display() const {
	cout << this->numerator << " / " << this->denominator;
}

int Rational::getNumerator() const {
	return this-> numerator;
}

int Rational::getDenominator() const {
	return this->denominator;
}

int Rational::gcd(int num1, int num2) const {
	int n1 = num1;
	int n2 = num2;
	while (n1 != n2) {
		if (n1 > n2) {
			n1 = n1 - n2;
		}
		else {
			n2 = n2 - n1;
		}
	}
	return n1;
}

// Do not change any of the code below this line!!

Rational getRational();
void displayResult(const string &, const Rational &, const Rational&, const Rational&);

int main() {
   Rational A, B, result;
   char choice;
   
   cout << "Enter Rational A:" << endl;
   A = getRational();
   cout << endl;
   
   cout << "Enter Rational B:" << endl;
   B = getRational();
   cout << endl;
   
   cout << "Enter Operation:" << endl
      << "a - Addition (A + B)" << endl
      << "s - Subtraction (A - B)" << endl
      << "m - Multiplication (A * B)" << endl
      << "d - Division (A / B)" << endl
      << "y - Simplify A" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 'a') {
      result = A.add(B);
      displayResult("+", A, B, result);
   } else if (choice == 's') {
      result = A.subtract(B);
      displayResult("-", A, B, result);
   } else if (choice == 'm') {
      result = A.multiply(B);
      displayResult("*", A, B, result);
   } else if (choice == 'd') {
      result = A.divide(B);
      displayResult("/", A, B, result);
   } else if (choice == 'y') {
      A.simplify();
      A.display();
   } else {
      cout << "Unknown Operation";
   }
   cout << endl;
   
   return 0;
}


Rational getRational() {
   int choice;
   int numer, denom;
   
   cout << "Which Rational constructor? (Enter 2, 1, or 0)" << endl
      << "2 - 2 parameters (numerator & denominator)" << endl
      << "1 - 1 parameter (numerator)" << endl
      << "0 - 0 parameters (default)" << endl;
   cin >> choice;
   cout << endl;
   
   if (choice == 2) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      cout << "denominator? ";
      cin >> denom;
      cout << endl;
      return Rational(numer, denom);
   } else if (choice == 1) {
      cout << "numerator? ";
      cin >> numer;
      cout << endl;
      return Rational(numer);
   } else {
      return Rational();
   }
}

void displayResult(const string &op, const Rational &lhs, const Rational&rhs, const Rational &result) {
   cout << "(";
   lhs.display();
   cout << ") " << op << " (";
   rhs.display();
   cout << ") = (";
   result.display();
   cout << ")";
}