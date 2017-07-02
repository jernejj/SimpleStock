#include "stockinterface.h"
class stockAle :
	public stockInterface
{
public:
	stockAle(int lDividend, int pValue, int fDividend=0, std::string name="Ale");
	~stockAle(void);
};

