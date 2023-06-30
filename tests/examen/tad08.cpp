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
PRUEBA: [ABB BASE: EXAMEN]
		Lista entrada: <23> /// Vector 1 salida [20,30,22,25,24,23]
		(Borrado intermedio en ABB: 23, 20, 24, 26, 25)
		Lista entrada: <23> /// Vector 2 salida [15,30,22,23]
		(Borrado intermedio en ABB: 15, 23, 22, 30)
		Lista entrada: <23> /// Vector 3 salida [10,23]
		(Borrado intermedio en ABB: 10, 5, 3)
		Lista entrada: <23> /// Vector 4 salida []
*/	
    TVectorCalendario v1, v2, v3, v4;
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

	TCalendario c23(1,1,2023,(char *)"fecha");

	
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

	l.Insertar(c23);
	
	v1 = a.ABBCamino(l);
	cout<< v1 <<endl;

// Borrado intermedio en ABB: 23, 20, 24, 26, 25)	
	a.Borrar(c23);
	a.Borrar(c20);
	a.Borrar(c24);
	a.Borrar(c26);
	a.Borrar(c25);
	v2 = a.ABBCamino(l);
	cout<< v2 <<endl;

//(Borrado intermedio en ABB: 15, 23, 22, 30)
	a.Borrar(c15);
	a.Borrar(c23);
	a.Borrar(c22);
	a.Borrar(c30);
	v3 = a.ABBCamino(l);
	cout<< v3 <<endl;

// (Borrado intermedio en ABB: 10, 5, 3)
	a.Borrar(c10);
	a.Borrar(c05);
	a.Borrar(c03);
	v4 = a.ABBCamino(l);
	cout<< v4 <<endl;
	
	return 0;
  }



