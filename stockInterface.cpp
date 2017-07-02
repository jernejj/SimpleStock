#include "stockInterface.h"
#include <math.h>


stockInterface::stockInterface(std::string name, int lDividend, int fDividend, int pValue):
stockName(name), lastDividend(lDividend), fixedDividend(fDividend), parValue(pValue)
{
}


stockInterface::~stockInterface(void)
{
	for (int i = 0; i < trades.size(); i++)
	{
		delete trades[i];
		trades.erase(trades.begin()+i);
	}
}

double
stockInterface::getDividendYield(int price)
{
	if (price <= 0)
	{
		return(-1);
	}
	return((double)lastDividend/(double)price);
}

double
stockInterface::getPERatio(int price)
{
	if (price < 0 || lastDividend <= 0)
	{
		return(-1);
	}

	return((double)price/(double)lastDividend);
}

void 
stockInterface::recordTrade(int qt, tindicator tInd, int tPrice)
{
	trade *markTrade = new trade(qt, tInd, tPrice);

	trades.push_back(markTrade);

}

double 
stockInterface::getGeometricMean()
{
	double geometric = 1;
	double power = 1.0/trades.size();

	if (trades.size() <= 0)
	{
		return(0);
	}

	for (int i = 0; i < trades.size(); i++)
	{
		trade *tmpTrade = trades[i];
		geometric *= (double)tmpTrade->tradePrice;
	}

	geometric = pow(geometric, power);

	return(geometric);
}

double
stockInterface::getVWSP(std::vector<trade *> trades)
{
	double vwsp = 0.0;
	int64 sumTPxqt = 0;
	int sumQt = 0;
	time_t timeNow;
	double timeCutOff = 900;

	time(&timeNow);

	for (int i = 0; i < trades.size(); i++)
	{
		double seconds = 0.0;
		trade *tmpTrade = trades[i];
		seconds = difftime(timeNow, tmpTrade->tradeTimeStamp);

		if (seconds <= timeCutOff)
		{
			sumTPxqt += (tmpTrade->tradePrice * tmpTrade->quantity);
			sumQt += tmpTrade->quantity;
		}
		
	}

	vwsp = sumTPxqt / sumQt;

	return(vwsp);
}