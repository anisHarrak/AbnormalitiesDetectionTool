#ifndef _UTP_BUFFER_H_
#define _UTP_BUFFER_H_


#include "gltpp_ringbuffer.hpp"
#include "record.h"


class UTPLFRingBuffer
	:	public gltpp_lf_ringbuffer<Record>
{
public:
	UTPLFRingBuffer( unsigned int size = RINGBUFFER_DEFAULT_SIZE );
	virtual ~UTPLFRingBuffer();
	virtual void reset( unsigned int new_size );
	virtual bool push( Record& rec );
	virtual bool pop( Record& rec , int* size=NULL);
	virtual unsigned int size();
	virtual bool isfull(int size=1500);
	virtual bool skip_next();
	virtual double usage();
};


#endif
