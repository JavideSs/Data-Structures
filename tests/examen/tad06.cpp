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
PRUEBA:  Lista entrada <25,27,38,40> /// Vector salida [20,30,22,25,26,27,20,30,38,20,30,38,40]
*/	
    TVectorCalendario v;
    TListaCalendario l;
    TABBCalendario a;


	TCalendario c20(1,1,2020,(char *)"fecha");
	TCalendario c10(1,1,2010,(char *)"fecha");
	TCalendario c30(1,1,2030,(char *)"fecha");
	TCalendario c05(1,1,2005,(char *)"fecha");
	TCalendario c15(1,1,2015,(char *)"fecha");
	TCalendario c22(1,1,2022,(char *)"fecha");
	TCalendario c25(1,1,2025,(char *)"fecha");
	TCalendario c24(1,1,2024,(char *)"fecha");
	TCalendario c26(1,1,2026,(char *)"fecha");
	TCalendario c03(1,1,2003,(char *)"fecha");

	TCalendario c27(1,1,2027,(char *)"fecha");
	TCalendario c38(1,1,2038,(char *)"fecha");
	TCalendario c40(1,1,2040,(char *)"fecha");

// ABB BASE (EJEMPLO EXAMEN): Insertar previamente en ABB los siguientes elementos: 20, 10, 30, 5, 15, 22, 25, 24, 26, 3
	a.Insertar(c20);
	a.Insertar(c10);
	a.Insertar(c30);
	a.Insertar(c05);
	a.Insertar(c15);
	a.Insertar(c22);
	a.Insertar(c25);
	a.Insertar(c24);
	a.Insertar(c26);
	a.Insertar(c03);

	l.Insertar(c25);
	l.Insertar(c27);
	l.Insertar(c38);
	l.Insertar(c40);

	v = a.ABBCamino(l);
	
	cout<< v <<endl;
	
	return 0;
  }



