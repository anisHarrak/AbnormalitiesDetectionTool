#include "utp_buffer.h"


UTPLFRingBuffer::UTPLFRingBuffer( unsigned int size )
	: gltpp_lf_ringbuffer<Record>( size )
{

}

UTPLFRingBuffer::~UTPLFRingBuffer()
{
}

void UTPLFRingBuffer::reset( unsigned int new_size )
{
	gltpp_lf_ringbuffer<Record>::reset( new_size );
}

bool UTPLFRingBuffer::push( Record& rec )
{
	return gltpp_lf_ringbuffer<Record>::push( rec );
}

bool UTPLFRingBuffer::pop( Record& rec ,int* size)
{
	return gltpp_lf_ringbuffer<Record>::pop( rec );
}

unsigned int UTPLFRingBuffer::size()
{
	return gltpp_lf_ringbuffer<Record>::size();
}
bool UTPLFRingBuffer::isfull(int size)
{
	return gltpp_lf_ringbuffer<Record>::isfull();
}

bool UTPLFRingBuffer::skip_next()
{
	return gltpp_lf_ringbuffer<Record>::skip_next();
}

double UTPLFRingBuffer::usage()
{
	return gltpp_lf_ringbuffer<Record>::usage();
}

