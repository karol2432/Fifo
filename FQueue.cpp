
#include "FQueue.h"

int FQueue::FQEnqueue( FQINFO* pInfo )//sluzy do dodawania elementu do kolejki
{
	FifoItem* nElem = new(nothrow) FifoItem( pInfo );
	if( !nElem )
	{
		throw FifoException( FIFO_ALLOCATION_ERROR );
	}
	if( this->FQEmpty() ) //jesli pusta to na glowie i ogonie ustawiam nowy element
	{
		this->m_pHead = nElem;
		this->m_pTail = nElem;
	}
	else
	{
		this->m_pTail->m_pNext = nElem;
		this->m_pTail = nElem;
	}
	
	return 0;
}

FQINFO* FQueue::FQDequeue() //sluzy do usuwania i zwracania pierwszego elementu kolejki
{
	if( this->FQEmpty() )
	{
		throw FifoException( FIFO_QUEUE_EMPTY );
	}
	FQINFO* elem = this->m_pHead->m_pItem;
	this->FQdel();
	return elem;
}

void  FQueue::FQClear() //czysci kolejke
{
	while( !(this->FQEmpty()) )
	{
		FQdel();
	}
}
void FQueue::FQPrintQueue()
{
	if( this->FQEmpty() )
	{
		throw FifoException( FIFO_QUEUE_EMPTY );
	}
	FifoItem* elem = this->m_pHead;
	while( elem != NULL ) //jak sie da (elem != this->m_pTail) to drukuje o jeden element mniej
	{
		cout << *(elem->m_pItem);
		elem = elem->m_pNext;
	}
}
void FQueue::FQdel() //usuwa mi jeden element z kolejki
{
	
	if( this->FQEmpty() )this->m_pTail = NULL;
	else
	{
		FifoItem* p = this->m_pHead;
		this->m_pHead = p->m_pNext;
		delete p;
	}
	
}