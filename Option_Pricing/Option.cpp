/*
Author: Rohan Chetan Thanki
Date created: 06-Oct-2021
*/

/*
This contains the implementation of the Option class
*/

#include "Option.hpp"
#include <string>
#include <sstream>

using namespace std;

/******************************* Constructors and Destructors ***************************************/

// Default constructor
Option::Option() : K(0), S(0), r(0), T(0), vol(0) { }

// Copy constructor
Option::Option(const Option& obj) : K(obj.getStrikePrice()), S(obj.getSpotPrice()), r(obj.getRiskFreeRate()), T(obj.getTimeToMaturity()), vol(obj.getVolatility()) { }

// Parametrised constructor
Option::Option(const double& K1, const double& S1, const double& r1, const double& T1, const double& vol1) : K(K1), S(S1), r(r1), T(T1), vol(vol1) { }

// Destructor
Option::~Option(void) { }

/************************************ Getters  ***********************************************/

double Option::getStrikePrice(void) const {	return K; }
double Option::getSpotPrice(void) const { return S; }
double Option::getRiskFreeRate(void) const { return r; }
double Option::getTimeToMaturity(void) const { return T; }
double Option::getVolatility(void) const { return vol; }

/************************************ Setters  ***********************************************/

void Option::setStrikePrice(const double& strikePrice) { K = strikePrice; }
void Option::setSpotPrice(const double& strikePrice) { S = strikePrice; }
void Option::setRiskFreeRate(const double& strikePrice) { r = strikePrice; }
void Option::setTimeToMaturity(const double& strikePrice) { T = strikePrice; }
void Option::setVolatility(const double& strikePrice) { vol = strikePrice; }
