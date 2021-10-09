# ISYE/Math 6767 : Design and Implementation of Systems to Support Computational Finance

Assignment 3
Submitted by: Rohan Thanki
GT ID: 903630513

## Projects sumbitted
1. Option_Pricing
	* This contains the source code of the classes and the implementation

2. Option_Pricing_Unit_Test - This contains the test cases
	* The Microsoft C++ Unit Testing Framework is used

## Classes
* Pricing_Method - this is an abstract base class in which we have different pricing methods
* Option - this class has the structure of an option
* Option_Price - this is derived from the Pricing_Method and Option classes. It containts the implementation of the pricing methods for call and put options using the Black Scholes model and the Binomial Asset Pricing Model

## Main File
This call the Option_Price class. The user inputs the following paramters:
* Option type - 'C' or 'c' for call option and 'P' or 'p' for put option. If any other character is entered, an exception will be thrown
* Strike price
* Spot price of the underlying asset
* Risk free interest rate
* Time to maturity
* Annualised volatiltiy of the underlying asset
* Number of steps in the binomial asset pricing model

Then the price of the option is printed when evaluated using the Black Scholes model and the Binomial model. We see that the Binomial model converges to the Black Scholes model when we increase the number of steps.