/*
Author: Rohan Chetan Thanki
Date created: 06-Oct-2021
*/

/*
This contains the implementation of the Option_Price class
*/

#include "Option_Price.hpp"
#include "Option.hpp"
#include <string>
#include <sstream>
#include <vector>

//#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

using namespace boost::math;
using namespace std;

/******************************* Constructors and Destructors ***************************************/

// Default constructor
Option_Price::Option_Price() : Option(), flag('c') { }

// Parametrised constructor
Option_Price::Option_Price(const double& K1, const double& S1, const double& r1, const double& T1, const double& vol1, const char& optionType) : Option(K1, S1, r1, T1, vol1), flag(optionType)
{
	if (!(optionType == 'c' || optionType == 'C' || optionType == 'p' || optionType == 'P'))
		throw(20);
}

// Destructor
Option_Price::~Option_Price(void) { }

/************************************ Getters ************************************************/

char Option_Price::getFlag(void) const { return flag; }

/************************************ Setters ************************************************/

void Option_Price::setFlag(const char& ch) { flag = ch; }

/******************************* Other Functions ***************************************/

double Option_Price::N(const double& x) const
{
	normal_distribution<> stdNormal(0.0, 1.0);
	return(cdf(stdNormal, x));
}

double Option_Price::Black_Scholes_Option_Price() const
{
	double K = getStrikePrice();
	double S = getSpotPrice();
	double r = getRiskFreeRate();
	double T = getTimeToMaturity();
	double sigma = getVolatility();

	Option opt1(K, S, r, T, sigma);
	
	double d1 = (log(S / K) + ((r + (pow(sigma, 2)/2)) * T)) / (sigma * sqrt(T));
	double d2 = d1 - (sigma * sqrt(T));
	
	if (flag == 'c' || flag == 'C')
		return (S * N(d1)) - (K * exp(-r * T) * N(d2));
	else if (flag == 'p' || flag == 'P')
		return (K * exp(-r * T) * N(-d2)) - (S * N(-d1));
	else
		throw(10);
}

double Option_Price::Binomial_Option_Price(const int& numSteps) const
{
	double K = getStrikePrice();
	double S = getSpotPrice();
	double r = getRiskFreeRate();
	double T = getTimeToMaturity();
	double sigma = getVolatility();
	
	// defining lattice parameters
	double dt = T / numSteps;
	double U = exp(sigma * sqrt(dt));
	double D = 1 / U;
	double R = exp(r * dt);

	// risk neutral probabilities
	double qu = (R-D) / (U-D);
	double qd = 1 - qu;

	// creating vector for stock price at maturity
	vector<double>stockPricesMaturity;
	for (int i = -numSteps; i <= numSteps; i+=2)
	{
		stockPricesMaturity.push_back(S * pow(U, i));
	}

	// pricing the option
	int tj = numSteps;
	vector<double> vecj;
	

	//creating vector of option payoff at maturity
	for (int j = 0; j <= stockPricesMaturity.size()-1; j++)
	{
		if (flag == 'c' || flag == 'C')
			vecj.push_back(max<double>(0, stockPricesMaturity[j] - K));
		else if (flag == 'p' || flag == 'P')
			vecj.push_back(max<double>(0, K - stockPricesMaturity[j]));
		else
			throw(20);
	}

	// back-propagation of option value to time = 0;
	for (int ti = numSteps - 1; ti >= 0; ti--)
	{
		vector<double> veci;
		for (int i = 0; i <= ti; i++)
		{
			veci.push_back((qd * vecj[i] + qu * vecj[i + 1]) / R);
		}
		vecj = veci;
	}

	return vecj[0];
}