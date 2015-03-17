/*#############################################################################*/
/*                              P' TEMPLATE                                    */
/*-----------------------------------------------------------------------------*/
/* gltpp_ringbuffer.hpp                                                        */
/*-----------------------------------------------------------------------------*/
/* Modifications :                                                             */
/*    - 15/03/2004 : creation (JCH)                                            */
/*-----------------------------------------------------------------------------*/
/* Description:                                                                */
/* This class is used to store message received by the main thread. Those      */
/* are despool by the second thread...                                         */
/*-----------------------------------------------------------------------------*/
#if defined(OS_SOL)||defined(OS_NT)
#pragma ident "$Header: //depot/SHARE_SLC_SLE/ALL_TEMPLATE_PP/prod/9.1.1/inc/gltpp_ringbuffer.hpp#2 $"
#endif
#define GLTPP_RINGBUFFER_H_Version "@(#) $Revision: #2 $"
/*#############################################################################*/


#ifndef GLTPP_RINGBUFFER_INCLUDE
#define GLTPP_RINGBUFFER_INCLUDE

#define RINGBUFFER_DEFAULT_SIZE (50)
#define MAX_RINGBUFFER RINGBUFFER_DEFAULT_SIZE

#include <stddef.h>
#include <stdlib.h>
#include <malloc.h>
#include <typeinfo>


//------------------------------------------------------------------------------
// Lock-free ringbuffer
//------------------------------------------------------------------------------
// ( mono-producer, mono-consumer )
//------------------------------------------------------------------------------

template<typename T>
class gltpp_lf_ringbuffer
{

protected:
	size_t	m_size;
	T*	m_buffer;

	T*	m_first_ptr		/*__attribute__((__aligned__(64)))*/;
	T*	m_last_ptr		/*__attribute__((__aligned__(64)))*/;
	T*	m_read_ptr		/*__attribute__((__aligned__(64)))*/;
	size_t	m_items_nb	/*__attribute__((__aligned__(64)))*/;

public:

	void reset( const size_t mbmaxelem )
	{
		free( m_buffer );
		m_buffer = (T*)malloc( mbmaxelem * sizeof( T ) );
		m_size = mbmaxelem;

		m_first_ptr		= m_buffer;
		m_read_ptr		= m_buffer;
		m_last_ptr		= m_buffer;
		m_items_nb		= 0;
	}

	bool push( const T& data )
	{
		bool ret = false;

		while ( m_first_ptr != m_read_ptr )
		{
			--m_items_nb;

			if ( ++m_first_ptr == m_buffer + m_size )
			{
				m_first_ptr = m_buffer;
			}
		}

		T* tmp_ptr = m_last_ptr + 1;

		if ( tmp_ptr == m_buffer + m_size )
		{
			tmp_ptr = m_buffer;
		}

		if ( tmp_ptr != m_read_ptr )
		{
			++m_items_nb;

			*m_last_ptr = data;
			m_last_ptr = tmp_ptr;

			ret = true;
		}

		return ret;
	}

	bool pop( T& data )
	{
		bool ret = false;

		T* tmp_ptr = m_read_ptr;

		if ( tmp_ptr != m_last_ptr )
		{
			data = *tmp_ptr;

			if ( ++tmp_ptr == m_buffer + m_size )
			{
				tmp_ptr = m_buffer;
			}

			m_read_ptr = tmp_ptr;
			ret = true;
		}

		return ret;
	}

	bool skip_next()
	{
		bool ret = false;

		T* tmp_ptr = m_read_ptr;

		if ( tmp_ptr != m_last_ptr )
		{
			if ( ++tmp_ptr == m_buffer + m_size )
			{
				tmp_ptr = m_buffer;
			}

			m_read_ptr = tmp_ptr;
			ret = true;
		}

		return ret;
	}

	double usage() const
	{
		return ( (double)size() * 100.0 / m_size );
	}

	bool isfull() const
	{
		T* tmp_ptr = m_last_ptr + 1;

		if ( tmp_ptr == m_buffer + m_size )
		{
			tmp_ptr = m_buffer;
		}

		return ( tmp_ptr == m_read_ptr );
	}

	size_t size() const
	{
		int n = m_last_ptr - m_read_ptr;
		return (size_t)( n >= 0 ? n : n + m_size );
	}

	gltpp_lf_ringbuffer( const size_t mbmaxelem = RINGBUFFER_DEFAULT_SIZE )
	:	m_buffer(0), m_size(0)
	{
		reset( mbmaxelem );
	}

	~gltpp_lf_ringbuffer()
	{
		free( m_buffer );
	}

};

#endif
