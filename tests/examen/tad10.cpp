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
PRUEBA:  ABB degenerado,con TCalendarios (1,1,2000,NULL) ... (1,1,2200,NULL) /// Lista entrada <2201> /// Vector salida [2000 ... 2201]
*/	
    TVectorCalendario v;
    TListaCalendario l;
    TABBCalendario a;

	TCalendario c201(1,1,2201,(char *)"fecha");
	
	for (int i=2000; i<=2200;i++)
	{
		TCalendario x(1,1,i,NULL);
		a.Insertar(x);
	}

	l.Insertar(c201);
		
	v = a.ABBCamino(l);
	
	cout<< v <<endl;
	
	return 0;
  }



