#include <iostream>
#include "ComplexNumber.h"

using namespace std;

//Default no-arg constructor
ComplexNumber::ComplexNumber() {
	real = 0;
	imag = 0;
}

//2-arg constructor
ComplexNumber::ComplexNumber(double real_part, double imaginary_part) {
	real = real_part;
	imag = imaginary_part;
}

//copy constructor
ComplexNumber::ComplexNumber(const ComplexNumber & rhs) {
	real = rhs.real;
	imag = rhs.imag;
}

//print method
void ComplexNumber::print(ostream & out) const {			
	out << real;
	if (imag < 0) {
		out << " - " << (imag * (-1)) << "i";
	}
	else {
		out << " + " << imag << "i";
	}
}

//equality comparison
bool ComplexNumber::equals(const ComplexNumber & rhs) const {
	if (real == rhs.real && imag == rhs.imag) {
		return true;
	}
	else {
		return false;
	}
}

//equal sign overload
const ComplexNumber & ComplexNumber::operator=(const ComplexNumber & rhs){
	real = rhs.real;
	imag = rhs.imag;
}

//plus equal overload
const ComplexNumber & ComplexNumber::operator+=(const ComplexNumber & rhs){
	real += rhs.real;
	imag += rhs.imag;
}

//minus equal overload
const ComplexNumber & ComplexNumber::operator-=(const ComplexNumber & rhs){
	real -= rhs.real;
	imag -= rhs.imag;
}

//multiply equal overload
const ComplexNumber & ComplexNumber::operator*=(const ComplexNumber & rhs){
	double tmpreal = (real * rhs.real) - (imag * rhs.imag);
	imag = (real * rhs.imag) + (imag * rhs.real);
	real = tmpreal;
}

//addition
ComplexNumber::ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber sum = lhs;
	sum += rhs;
	return sum;
}

//subtraction
ComplexNumber::ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs){
	ComplexNumber tmp = lhs;
	tmp -= rhs;
	return tmp;
}

//multiplication
ComplexNumber::ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs) {
	ComplexNumber tmp = lhs;
	tmp *= rhs;
	return tmp;
}

//relational equals
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs) {
	ComplexNumber tmp = lhs;
	return tmp.equals(rhs);
}

//relational not equals
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs) {
	ComplexNumber tmp = lhs;
	return !tmp.equals(rhs);
}

//output << overload
ostream & operator<<(ostream & out, const ComplexNumber & rhs) {
	/*ComplexNumber tmp = rhs;
	out << tmp.real;
	if (tmp.imag < 0) {
		out << " - " << (tmp.imag * (-1)) << "i";
	}
	else {
		out << " + " << tmp.imag << "i";
	}*/
	rhs.print(out);
	return out;
}

//input >> overload
istream & operator>>(istream & in, ComplexNumber & n) {
	char ch;
	double r, i;
	int ipos = 1;

	//eat through whitespace
	in.get(ch);
	while (ch == ' ' || ch == '\n' || ch== '\t') {
		in.get(ch);
	}
	in.putback(ch);
	in >> r;	//read in real number value
	
	//eat through more whitespace
	in.get(ch);
	while (ch == ' ' || ch == '\n' || ch== '\t') {
		in.get(ch);
	}
	//check for + or -
	if (ch == '+') {
		ipos = 1;
		in.get(ch);
	}
	else if (ch == '-') {
		ipos = -1;
		in.get(ch);
	}
	else {
		cout<< ch<<'*';
		in.setstate(ios::failbit);
		return in;
	}
	//eat through more whitespace
	while (ch == ' ' || ch == '\n' || ch== '\t') {
		in.get(ch);
	}
	in.putback(ch);
	in >> i;	//read in imaginary number value

	in.get(ch);
	
	if (ch != 'i') {
		cout<<ch<<"*";
		in.get(ch);
		in.setstate(ios::failbit);
		return in;
	}
	
	//change imaginary number to negative if necessary
	i = i*ipos;
	
	//set the complex number
	n = ComplexNumber(r,i);
	
	//modify data members of n
	return in;
}
