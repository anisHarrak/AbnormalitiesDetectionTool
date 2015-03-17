#ifndef CHECKPRICE_H
#define CHECKPRICE_H

#include "checkMO.h"
#include <iostream>
#include <fstream>

class CheckPrice : public CheckMO
{
public:
	CheckPrice();
	~CheckPrice(){}
	CheckPrice(Database& BD);

	bool _checkBidPrice(Record& rec);
	bool _checkAskPrice(Record& rec);
	bool _checkBdvsAk(Record& rec);
	void run();
	bool start(int id=0);
};

#endif