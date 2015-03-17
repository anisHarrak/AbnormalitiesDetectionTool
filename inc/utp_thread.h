#ifndef __UTP_THREAD_H__
#define __UTP_THREAD_H__


#include "SCThread.hpp"
#include "SCMutex.hpp"



class UTPThread : public SCThread
{
public:
	UTPThread( );
	virtual ~UTPThread(){}

};

#endif
