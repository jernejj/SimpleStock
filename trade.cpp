#include "trade.h"


trade::trade(int qt, tindicator tInd, int tPrice):
quantity(qt), tradeIndicator(tInd), tradePrice(tPrice)
{
	time(&tradeTimeStamp);
}


trade::~trade(void)
{
}
