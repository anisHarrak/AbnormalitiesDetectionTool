#ifndef SLCFEEDGETTER_H
#define SLCFEEDGETTER_H

#include "check.h"
#include "checkPrice.h"
#include "SCConfig.hpp"         // Handles configuration files
#include "SCLogger.hpp"         // Logging facility
#include "SCRecord.hpp"         // Basic container for stream server messages
#include "SCGLSession.hpp"      // Handles a logical session with the server
#include "SCGLReferential.hpp"  // Defines all the stream server fields
#include <stdio.h>
#include <vector>

using namespace std;

class SLCFeedGetter : public UTPThread
{
private:
	Check* checker;
	UTPLFRingBuffer* buffer;

	SCGLSession session;
	bool result;
	
public:
	SLCFeedGetter();
	SLCFeedGetter(Check* checker);
	~SLCFeedGetter();
	bool start(int id=0);
	void stop();
	void run();
	bool configurerServeur( const char *filename);


	void setChecker(Check* _checker)
	{
		this->checker = _checker;
		this->buffer=_checker->getBuffer();
	}
	
};

#endif