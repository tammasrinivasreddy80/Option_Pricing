/*
Author: Rohan Chetan Thanki
Date created: 06-Oct-2021
*/

// This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Option_Price.hpp"

int main()
{
    // declaring variables
    char optionType;
    double K, S, r, T, sigma, numSteps;

    // reading input from user
    cout << "Enter option type - for call option enter c or C; for put option enter p or P: "; cin >> optionType;
    cout << "Enter strike price: "; cin >> K;
    cout << "Enter spot price: "; cin >> S;
    cout << "Enter risk free interest rate in absolute numbers (not in percentage): "; cin >> r;
    cout << "Enter time to maturity in years: "; cin >> T;
    cout << "Enter annualised volatility in absolute numbers (not in percentage): "; cin >> sigma;
    cout << "Enter number of steps in binomial model: "; cin >> numSteps;

    // pricing the option and printing the results
    Option_Price optPricer(K, S, r, T, sigma, optionType);
    cout << "\nOption price from Black-Scholes formula: " << optPricer.Black_Scholes_Option_Price() << endl;
    cout << "\nOption price from Binomial model: " << optPricer.Binomial_Option_Price(numSteps) << endl;

    cout << "\nend of main" << endl;
    return 0;
}
