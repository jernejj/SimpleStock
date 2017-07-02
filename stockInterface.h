#pragma once
#include <string>
#include <vector>
#include "trade.h"

typedef long int int64;

class stockInterface
{
public:
	stockInterface(std::string name, int lDividend, int fDividend, int pValue);
	~stockInterface(void);

	virtual double getDividendYield(int price);
	double getPERatio(int price);

	void recordTrade(int qt, tindicator tInd, int tPrice);

	double getGeometricMean();

	static double getVWSP(std::vector<trade *> trades);
	std::vector<trade*> trades;

protected:
	std::string stockName;
	int lastDividend;
	int fixedDividend;
	int parValue;
};

