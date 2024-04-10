// Fifo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include "FQueue.h"


int main()
{
  FQueue q;

  FQINFO* elem1 = new FQINFO( 1 );
  FQINFO* elem2 = new FQINFO( 2 );
  FQINFO* elem3 = new FQINFO( 3 );
  FQINFO* elem4 = new FQINFO( 4 );
  FQINFO* elem5 = new FQINFO( 5 );
  FQINFO* elem6 = new FQINFO( 6 );
  FQINFO* elem7 = new FQINFO( 7 );
  q.FQEnqueue( elem1 );
  q.FQEnqueue( elem2 );
  q.FQEnqueue( elem3 );
  q.FQEnqueue( elem4 );
  q.FQEnqueue( elem5 );
  q.FQEnqueue( elem6 );
  q.FQEnqueue( elem7 );

  cout << "Aktualna kolejka:"<<endl;
  q.FQPrintQueue();
  cout << "\n\n";

  FQInfo* temp = q.FQDequeue();
  cout << "Usuniety element kolejki: " << *temp<<endl;
  cout<< "Aktualna kolejka:" << endl;
  q.FQPrintQueue();
  cout << "\n\n";
  delete temp;
  q.FQClear(); //czyszczenie kolejki

  return 0;
}

