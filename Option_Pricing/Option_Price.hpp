/*
Author: Rohan Chetan Thanki
Date created: 06-Oct-2021
*/

/*
This contains the signature of the Option_Price class
*/

#include "Pricing_Method.hpp"
#include "Option.hpp"
#include <string>
#include <iostream>

using namespace std;

#ifndef Option_Price_HPP
#define Option_Price_HPP

class Option_Price : public Pricing_Method, public Option
{
private:
	char flag;
	double N(const double&) const;

public:

	// Constructors and Destructors
	Option_Price(void);
	Option_Price(const double&, const double&, const double&, const double&, const double&, const char&);
	virtual ~Option_Price(void);

	// Getters
	char getFlag(void) const;

	// Setters
	void setFlag(const char& ch);

	// Pricing
	double Black_Scholes_Option_Price() const override;
	double Binomial_Option_Price(const int&) const override;
};

#endif