#ifndef CHECK_H
#define CHECK_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>
#include "record.h"
#include "utp_thread.h"
#include "database.h"
#include "utp_buffer.h"

#define RINGBUFFER_DEFAULT_SIZE (50)

using namespace std;

class Check : public UTPThread
{
protected:
	Database BD;
	UTPLFRingBuffer	m_buffer;
	unsigned int	m_buffersize;

public:
	Check(unsigned int bsize = RINGBUFFER_DEFAULT_SIZE);
	Check(Database BD);
	virtual ~Check(){}
	virtual void stop();
	virtual void run();
	virtual bool update(Record& rec);
	//bool _checkAskPrice(Record& rec);
	bool IsBufferFull();
	unsigned int BufferSize();
	UTPLFRingBuffer* getBuffer()
	{
		return &m_buffer;
	}

	void setBD(Database _BD)
	{
		this->BD=_BD;
	}
	Database getBD() const
	{
		return BD;
	}

};
#endif