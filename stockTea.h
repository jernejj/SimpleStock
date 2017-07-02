#include "stockinterface.h"
class stockTea :
	public stockInterface
{
public:
	stockTea(int lDividend, int pValue, int fDividend=0, std::string name="Tea");
	~stockTea(void);
};

