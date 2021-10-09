/*
Author: Rohan Chetan Thanki
Date created: 06-Oct-2021
*/

/*
This contains the signature of the Pricing class
*/

#ifndef Pricing_Method_HPP
#define Pricing_Method_HPP

class Pricing_Method
{
public:
    virtual ~Pricing_Method(void);
    virtual double Black_Scholes_Option_Price() const = 0;
    virtual double Binomial_Option_Price(const int&) const = 0;
};

#endif