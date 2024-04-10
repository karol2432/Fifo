#pragma once
#include <iostream>
using namespace std;
#define FIFO_ALLOCATION_ERROR  0x01
#define FIFO_QUEUE_EMPTY 0x04
#define OTHER_ERROR      0x10
#include "global.h"

class FifoItem
{
public:
	friend class FQueue;
	FifoItem( FQINFO* pInfo = nullptr );//konstr z parametrem domyslnym (NULL) - wsk na FQINFO 
	virtual ~FifoItem();
private:
	FQINFO* m_pItem; // wsk m_pItem (wsk na FQINFO), 
	FifoItem* m_pNext; //wsk m_pNext (wsk na nastepny w kolejce)
	
};
//===========INLINE FUNCTION==============
inline FifoItem::FifoItem( FQINFO* pInfo )
{
	this->m_pItem = pInfo;
	this->m_pNext = NULL;
}
inline FifoItem::~FifoItem()
{
}
//--------------------------------

class FQueue
{
public:
	FQueue(); //konstruktor bez param
	virtual ~FQueue(); // wirt destr
	bool FQEmpty();
	int FQEnqueue( FQINFO* pInfo );
	FQINFO* FQDequeue();
	void  FQClear();
	void FQPrintQueue();
private:
	void FQdel();
	FifoItem* m_pHead;
	FifoItem* m_pTail;
};

//======================INLINE FUNCTIONS==========
inline FQueue::FQueue()
{
	this->m_pHead = NULL;
	this->m_pTail = NULL;
}
inline FQueue::~FQueue()
{
	FQClear();
}
inline bool FQueue::FQEmpty()
{
	return !(this->m_pHead);
}

//----------------------

class FifoException
{
public:
	FifoException( int errCode = OTHER_ERROR );
	const char* getReason()const;
private:
	int m_errCode;
};
//==========INLINE FUNCTION========
inline FifoException::FifoException( int errCode )
{
	this->m_errCode = errCode;
}

inline const char* FifoException::getReason()const
{
	switch( this->m_errCode )
	{
	case FIFO_ALLOCATION_ERROR: return "Error: FIFO_ALLOCATION_ERROR!!!";
	case  FIFO_QUEUE_EMPTY: return "Error: FIFO_QUEUE_EMPTY!!!";
	case OTHER_ERROR:
	default: return "Error: OTHER_ERROR!!!";
	}
}