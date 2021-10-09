#include "pch.h"
#include "CppUnitTest.h"
#include "../Option_Pricing/Pricing_Method.hpp"
#include "../Option_Pricing/Option.hpp"
#include "../Option_Pricing/Option_Price.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OptionPricingUnitTest
{
	TEST_CLASS(OptionPricingUnitTest)
	{
	public:		
		TEST_METHOD(Test1_Black_Scholes)
		{
			const double K = 110;
			const double S = 100;
			const double r = 0.02;
			const double T = 1;
			const double sigma = 0.3;
			const double callPriceTrue = 8.864;
			const double putPriceTrue = 16.686;
			
			Option_Price optPricerCall(K, S, r, T, sigma, 'c');
			Option_Price optPricerPut(K, S, r, T, sigma, 'p');
			double callPrice = optPricerCall.Black_Scholes_Option_Price();
			double putPrice = optPricerPut.Black_Scholes_Option_Price();
			cout << callPrice << endl;
			cout << putPrice << endl;
			Assert::IsTrue(abs(callPrice - callPriceTrue) < 0.01);
			Assert::IsTrue(abs(putPrice - putPriceTrue) < 0.01);
			Assert::IsTrue(true);
		}

		TEST_METHOD(Test2_Binomial_Model)
		{
			const double K = 110;
			const double S = 100;
			const double r = 0.02;
			const double T = 1;
			const double sigma = 0.3;
			const int numSteps = 10000;
			const double callPriceTrue = 8.864;
			const double putPriceTrue = 16.686;

			Option_Price optPricerCall(K, S, r, T, sigma, 'c');
			Option_Price optPricerPut(K, S, r, T, sigma, 'p');
			double callPrice = optPricerCall.Binomial_Option_Price(numSteps);
			double putPrice = optPricerPut.Binomial_Option_Price(numSteps);
			cout << callPrice << endl;
			cout << putPrice << endl;
			Assert::IsTrue(abs(callPrice - callPriceTrue) < 0.01);
			Assert::IsTrue(abs(putPrice - putPriceTrue) < 0.01);
			Assert::IsTrue(true);
		}
	};
}