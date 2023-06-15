#pragma once
#include <iostream>
using namespace std;

class FractionException {
public:
	FractionException(const string&);
	string& what();
private:
	string msg;
};

class Fraction {
private:
    int num;
    int dem;
public:
    Fraction();
    Fraction(int);
    Fraction (int, int);
    
    int numerator() const;
    int denominator() const;
        
    // unary operators
    Fraction& operator++();
    Fraction operator++(int);
    Fraction operator+=(const Fraction& value);
    Fraction& operator-();
};

// addition cases
Fraction operator+(const Fraction& left, const Fraction& right);
        
// subtraction cases
Fraction operator-(const Fraction& left, const Fraction& right);
        
// multiplication cases
Fraction operator*(const Fraction& left, const Fraction& right);
        
// division cases
Fraction operator/(const Fraction& left, const Fraction& right);

// less than cases
bool operator<(const Fraction& left, const Fraction& right);

// less than or equal to cases
bool operator<=(const Fraction& left, const Fraction& right);

// greater than cases
bool operator>(const Fraction& left, const Fraction& right);

// greater than or equal to cases
bool operator>=(const Fraction& left, const Fraction& right);

// equal to cases
bool operator==(const Fraction& left, const Fraction& right);

// does not equal to cases
bool operator!=(const Fraction& left, const Fraction& right);

int GCD(int num, int dem);

ostream& operator<<(ostream& out, const Fraction& value);
istream& operator>>(istream& in, Fraction& value);