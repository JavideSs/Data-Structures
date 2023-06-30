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
PRUEBA:  [ABB BASE degenerado a IZQ. y DCHA. /// Lista entrada <5,15> /// Vector salida [10,9,8,7,6,5,10,11,12,13,14,15]
*/	
    TVectorCalendario v;
    TListaCalendario l;
    TABBCalendario a;

	TCalendario c05(1,1,2005,(char *)"fecha");
	TCalendario c06(1,1,2006,(char *)"fecha");
	TCalendario c07(1,1,2007,(char *)"fecha");
	TCalendario c08(1,1,2008,(char *)"fecha");
	TCalendario c09(1,1,2009,(char *)"fecha");
	TCalendario c10(1,1,2010,(char *)"fecha");
	TCalendario c11(1,1,2011,(char *)"fecha");
	TCalendario c12(1,1,2012,(char *)"fecha");
	TCalendario c13(1,1,2013,(char *)"fecha");
	TCalendario c14(1,1,2014,(char *)"fecha");
	TCalendario c15(1,1,2015,(char *)"fecha");

	a.Insertar(c10); // RAIZ
	
	a.Insertar(c11);
	a.Insertar(c12);
	a.Insertar(c13);
	a.Insertar(c14);
	a.Insertar(c09);
	a.Insertar(c08);
	a.Insertar(c07);
	a.Insertar(c06);
	
	l.Insertar(c05);
	l.Insertar(c15);

	v = a.ABBCamino(l);
	
	cout<< v <<endl;
	
	return 0;

  }



