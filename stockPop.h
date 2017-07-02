#include "stockinterface.h"
class stockPop :
	public stockInterface
{
public:
	stockPop(int lDividend, int pValue, int fDividend=0, std::string name="Pop");
	~stockPop(void);
};

