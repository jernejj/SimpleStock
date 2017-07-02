#pragma once
#include <time.h>


enum tindicator {buy, sell};

class trade
{
public:
	trade(int qt, tindicator tInd, int tPrice);

	~trade(void);

public:
	time_t tradeTimeStamp;
	int quantity;
	tindicator tradeIndicator;
	int tradePrice;
};

