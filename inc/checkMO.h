#ifndef CHECKMO_H
#define CHECKMO_H

#include "check.h"

using namespace std;

class CheckMO : virtual public Check
{
public:
	CheckMO();
	virtual ~CheckMO(){}
	virtual bool start(int id=0)=0;

};
#endif                                                                                                                   