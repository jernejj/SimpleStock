#include "stockAle.h"
#include "stockGin.h"
#include "stockJoe.h"
#include "stockPop.h"
#include "stockTea.h"
#include <iostream>
#include <windows.h>


using namespace std;

stockAle *sAle = NULL;
stockGin *sGin = NULL;
stockJoe *sJoe = NULL;
stockPop *sPop = NULL;
stockTea *sTea = NULL;

void testDividendYield()
{
	double dividenYield = 0.0;

	dividenYield = sTea->getDividendYield(23);
	cout << "Tea Dividend yield is " << dividenYield << " correct is 0" << endl;

	dividenYield = sTea->getDividendYield(3466);
	cout << "Tea Dividend yield is " << dividenYield << " correct is 0" << endl;

	dividenYield = sPop->getDividendYield(23);
	cout << "Pop Dividend yield is " << dividenYield << " correct is " << 0.347826 << endl;

	dividenYield = sPop->getDividendYield(3466);
	cout << "Pop Dividend yield is " << dividenYield << " correct is " << 0.00230814 << endl;

	dividenYield = sAle->getDividendYield(23);
	cout << "Ale Dividend yield is " << dividenYield << " correct is " << 1.0 << endl;

	dividenYield = sAle->getDividendYield(3466);
	cout << "Ale Dividend yield is " << dividenYield << " correct is " << 0.00663589 << endl;

	dividenYield = sGin->getDividendYield(23);
	cout << "Gin Dividend yield is " << dividenYield << " correct is " << 0.0869565 << endl;

	dividenYield = sGin->getDividendYield(3466);
	cout << "Gin Dividend yield is " << dividenYield << " correct is " << 0.000577034 << endl;

	dividenYield = sJoe->getDividendYield(23);
	cout << "Joe Dividend yield is " << dividenYield << " correct is " << 0.5652173913043478 << endl;

	dividenYield = sJoe->getDividendYield(3466);
	cout << "Joe Dividend yield is " << dividenYield << " correct is " << 0.0037507212925563 << endl;
}

void testGeometricMeanAndVWSP()
{
	double geometricMean;
	double vwsp;
	vector<trade *> trades;

	sTea->recordTrade(2, sell, 15);
	sTea->recordTrade(10, sell, 15);
	sTea->recordTrade(4, sell, 15);

	sPop->recordTrade(2, sell, 20);
	sPop->recordTrade(10, sell, 20);
	sPop->recordTrade(4, sell, 20);

	sAle->recordTrade(2, sell, 18);
	sAle->recordTrade(10, sell, 18);
	sAle->recordTrade(4, sell, 18);

	sGin->recordTrade(2, sell, 32);
	sGin->recordTrade(10, sell, 32);
	sGin->recordTrade(4, sell, 32);

	sJoe->recordTrade(2, sell, 13);
	sJoe->recordTrade(10, sell, 13);
	sJoe->recordTrade(4, sell, 13);

 	Sleep(905*1000);

	sTea->recordTrade(2, sell, 10);
	sPop->recordTrade(2, sell, 10);
	sAle->recordTrade(2, sell, 10);
	sGin->recordTrade(2, sell, 10);
	sJoe->recordTrade(2, sell, 10);

	geometricMean = sTea->getGeometricMean();
    cout << "Tea geometricMean is " << geometricMean << " correct is 13.554" << endl;

	geometricMean = sPop->getGeometricMean();
	cout << "Pop geometricMean is " << geometricMean << " correct is 16.8179" << endl;

	geometricMean = sAle->getGeometricMean();
	cout << "Ale geometricMean is " << geometricMean << " correct is 15.5401" << endl;

	geometricMean = sGin->getGeometricMean();
	cout << "Gin geometricMean is " << geometricMean << " correct is 23.9256" << endl;

	geometricMean = sJoe->getGeometricMean();
	cout << "Joe geometricMean is " << geometricMean << " correct is 23.9256" << endl;


	trades.insert(trades.end(), sTea->trades.begin(), sTea->trades.end());
	trades.insert(trades.end(), sPop->trades.begin(), sPop->trades.end());
	trades.insert(trades.end(), sAle->trades.begin(), sAle->trades.end());
	trades.insert(trades.end(), sGin->trades.begin(), sGin->trades.end());
	trades.insert(trades.end(), sJoe->trades.begin(), sJoe->trades.end());

	vwsp = stockInterface::getVWSP(trades);
	cout << "Joe vwsp is " << vwsp << " correct is 10" << endl;
}

void testPERatio()
{
	double peRation = 0.0;

	peRation = sTea->getPERatio(23);
	cout << "Tea PERatio is " << peRation << " correct is -1" << endl;

	peRation = sTea->getPERatio(3466);
	cout << "Tea PERatio is " << peRation << " correct is -1" << endl;

	peRation = sPop->getPERatio(23);
	cout << "Pop PERatio is " << peRation << " correct is " << 2.875 << endl;

	peRation = sPop->getPERatio(3466);
	cout << "Pop PERatio is " << peRation << " correct is " << 433.25 << endl;

	peRation = sAle->getPERatio(23);
	cout << "Ale PERatio is " << peRation << " correct is " << 1.0 << endl;

	peRation = sAle->getPERatio(3466);
	cout << "Ale PERatio is " << peRation << " correct is " << 150.695652173913 << endl;

	peRation = sGin->getPERatio(23);
	cout << "Gin PERatio is " << peRation << " correct is " << 2.875 << endl;

	peRation = sGin->getPERatio(3466);
	cout << "Gin PERatio is " << peRation << " correct is " << 433.25 << endl;

	peRation = sJoe->getPERatio(23);
	cout << "Joe PERatio is " << peRation << " correct is " << 1.769230769230769 << endl;

	peRation = sJoe->getPERatio(3466);
	cout << "Joe PERatio is " << peRation << " correct is " << 266.6153846153846 << endl;
}

int main(void)
{
	sTea = new stockTea(0, 100);
	sPop = new stockPop(8, 100);
	sAle = new stockAle(23, 60);
	sGin = new stockGin(8, 100, 2);
	sJoe = new stockJoe(13, 250);


	testDividendYield();
	testPERatio();
	testGeometricMeanAndVWSP();

	delete(sTea);
	delete(sPop);
	delete(sAle);
	delete(sGin);
	delete(sJoe);
	return(0);
}