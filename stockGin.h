#include "stockinterface.h"

class stockGin :
	public stockInterface
{
public:
	stockGin(int lDividend, int pValue, int fDividend, std::string name="Gin");
	~stockGin(void);

	double getDividendYield(int price);
};

