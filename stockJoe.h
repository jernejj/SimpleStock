#include "stockinterface.h"
class stockJoe :
	public stockInterface
{
public:
	stockJoe(int lDividend, int pValue, int fDividend=0, std::string name="Joe");
	~stockJoe(void);
};

