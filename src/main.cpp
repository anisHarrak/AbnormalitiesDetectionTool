#include "slcFeedGetter.h"
#include "check.h"
#include "checkPrice.h"
#include "utp_buffer.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{

	//Check* checker = new Check() ;
	Check* checker_price= new CheckPrice();
	//SLCFeedGetter* slcFeedGetter = new  SLCFeedGetter(buffer,checker);

	//SLCFeedGetter* slcFeedGetter = new  SLCFeedGetter(checker);
	SLCFeedGetter* slcFeedGetter = new  SLCFeedGetter(checker_price);
	//slcFeedGetter->setChecker(checker);
	slcFeedGetter->start();

	return 0;
}