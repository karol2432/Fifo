#pragma once
#include <iostream>
using namespace std;
#define FQINFO FQInfo //zdef stala preprocesora FQINFO jako struktura FQInfo
class FQInfo
{
public:
	FQInfo( int nKey=0 );
	virtual ~FQInfo();
	friend ostream& operator<<( ostream& out, const FQINFO& Fq );
private:
	int* p;
	int m_nKey;
};

//===========INLINE FUNCTION============
inline FQInfo::FQInfo( int nKey )
{
	this->m_nKey=nKey;
	p = new int[2];//alokacja new(nothrow)
	p[0] = nKey; 
	p[1] = nKey;
}

inline FQInfo::~FQInfo()
{
	delete p;
}
