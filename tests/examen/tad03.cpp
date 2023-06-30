#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"

using namespace std;

int
main(void)
{
/*
PRUEBA:  [ABB BASE degenerado a  DCHA. /// Lista entrada <5,13,17> /// Vector salida [10,5,10,11,15,12,13,10,11,15,16,17]
*/	
    TVectorCalendario v;
    TListaCalendario l;
    TABBCalendario a;

	TCalendario c05(1,1,2005,(char *)"fecha");
	TCalendario c10(1,1,2010,(char *)"fecha");
	TCalendario c11(1,1,2011,(char *)"fecha");
	TCalendario c12(1,1,2012,(char *)"fecha");
	TCalendario c13(1,1,2013,(char *)"fecha");
	TCalendario c15(1,1,2015,(char *)"fecha");
	TCalendario c16(1,1,2016,(char *)"fecha");
	TCalendario c17(1,1,2017,(char *)"fecha");

	a.Insertar(c10); // RAIZ
	
	a.Insertar(c11);
	a.Insertar(c15);
	a.Insertar(c12);
	a.Insertar(c16);
	
	l.Insertar(c05);
	l.Insertar(c13);
	l.Insertar(c17);

	v = a.ABBCamino(l);
	
	cout<< v <<endl;
	
	return 0;

  }



