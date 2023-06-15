#include <iostream>
using namespace std;

#include "fraction_test.h"

// fraction exception
FractionException::FractionException(const string& msg) : msg(msg) { }
string& FractionException::what() {return msg;}

// recursive function to find the GCD
int GCD(int num, int dem) {
   if (dem == 0) return num;
   return GCD(dem, num % dem);
}

Fraction::Fraction() {
    num = 0;
    dem = 1;
}

// fraction: single integer input
Fraction::Fraction(int num_) {
   num = num_;
   dem = 1;
}

Fraction::Fraction(int num_, int dem_) {
   if (dem_ == 0) {
      throw FractionException("Error. Cannot Divide by 0");
   }
   
   int GCD_ = GCD(num_, dem_); // find the GCD
   
   if (num_ > 0 && dem_ < 0) { // if numerator is positive and denominator is negative
      num = -num_ / GCD_;
      dem = -dem_ / GCD_;
   }
   else if (num_ < 0 && dem_ < 0) { // if both numerator and denominator are negative
         num = -num_ / GCD_;
         dem = -dem_ / GCD_;
   }
   else {
      num = num_ / GCD_; // divide by GCD
      dem = dem_ / GCD_;
   }
}

// accessors
int Fraction::numerator() const { return num; }
int Fraction::denominator() const { return dem; }

// output overload
ostream& operator<<(ostream& out, const Fraction& value) {
    out << value.numerator() << "/" << value.denominator();
    return out;
}

// input overload
istream& operator>>(istream& in, Fraction& value) {
    int num, dem;
    in >> num >> dem;
    value = Fraction(num, dem);
    return in;
}

// addition cases
Fraction operator+(const Fraction& left, const Fraction& right) {
   return Fraction (left.numerator()*right.denominator() + right.numerator()*left.denominator(), left.denominator()*right.denominator());
}

// subtraction cases
Fraction operator-(const Fraction& left, const Fraction& right) {
   return Fraction (left.numerator()*right.denominator() - right.numerator()*left.denominator(), left.denominator()*right.denominator());
}

// multiplication cases
Fraction operator*(const Fraction& left, const Fraction& right) {
   return Fraction(left.numerator() * right.numerator(), left.denominator() * right.denominator());
}

// division cases
Fraction operator/(const Fraction& left, const Fraction& right) {
   return Fraction(left.numerator() * right.denominator(), left.denominator() * right.numerator());
}

Fraction operator-(const Fraction& value) {
   Fraction result(-value.numerator(), value.denominator());
   return result;
}

// less than <
bool operator<(const Fraction& left, const Fraction& right) {
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 < temp2;
}

// less than or equal to <=
bool operator<=(const Fraction& left, const Fraction& right) {
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 <= temp2;
}

// greater than >
bool operator>(const Fraction& left, const Fraction& right){
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 > temp2;
}

// greater than or equal to >=
bool operator>=(const Fraction& left, const Fraction& right) {
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 >= temp2;
}

// equal to ==
bool operator==(const Fraction& left, const Fraction& right) {
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 == temp2;
}

// does not equal to !=
bool operator!=(const Fraction& left, const Fraction& right){
   float temp1 = left.numerator() / left.denominator();
   float temp2 = right.numerator() / right.denominator();
   return temp1 != temp2;
}

// unary operators
Fraction& Fraction::operator-() {
   num = -num;
   return *this;
}

Fraction& Fraction::operator++() {
   num = num + dem;
   return *this;
}

Fraction Fraction::operator++(int value) {
   Fraction temp (num, dem);
   num = num + dem;
   return temp;
}

Fraction Fraction::operator+=(const Fraction& right) {
   return Fraction(num * right.denominator() + right.numerator() * dem, dem * right.denominator());
}