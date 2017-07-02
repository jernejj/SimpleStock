#include "stockGin.h"


stockGin::stockGin(int lDividend, int pValue, int fDividend, std::string name):
stockInterface(name, lDividend, fDividend, pValue)
{
}

double
	stockGin::getDividendYield(int price)
{
	double yield;
	if (price <= 0)
	{
		return(-1);
	}

	yield = (double)(((double)fixedDividend/100 * (double)parValue)/(double)price);
	return(yield);
}

stockGin::~stockGin(void)
{
}
