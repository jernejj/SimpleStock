#include "stockPop.h"


stockPop::stockPop(int lDividend, int pValue, int fDividend, std::string name):
stockInterface(name, lDividend, fDividend, pValue)
{
}


stockPop::~stockPop(void)
{
}
