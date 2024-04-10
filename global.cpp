#include "global.h"

ostream& operator<<( ostream& out, const FQINFO& Fq )
{
	out << "Klucz = " << Fq.m_nKey << " : " << "Wartosc [ " << Fq.p[0] << " ]" << "\n";
	return out;
}
