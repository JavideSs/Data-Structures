#ifndef _TABBCALENDARIO_
    #define _TABBCALENDARIO_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"


class TNodoABB;

class TABBCalendario{
    //Salida
    friend std::ostream& operator<<(std::ostream&, const TABBCalendario&);

    private:
        TNodoABB* raiz;

        //Aux de "Preorden()"
        void PreordenAux(TVectorCalendario&, int& i) const;
        //Aux de "Inorden()"
        void InordenAux(TVectorCalendario&, int& i) const;
        //Aux de "Postorden()"
        void PostordenAux(TVectorCalendario&, int& i) const;

    public:
        //Constructor por defecto
        TABBCalendario();
        //Constructor de copia
        TABBCalendario(const TABBCalendario&);
        //Asignacion
        TABBCalendario& operator=(const TABBCalendario&);
        //Destructor
        ~TABBCalendario();

        //Incrementar
        TABBCalendario operator+(const TABBCalendario&) const;
        //Decrementar
        TABBCalendario operator-(const TABBCalendario&) const;

        //Igualdad
        bool operator==(const TABBCalendario&) const;

        //Altura
        int Altura() const;
        //Numero de nodos
        int Nodos() const;
        //Numero de hojas
        int NodosHoja() const;
        //Si ningun calendario existe
        bool EsVacio() const;

        //Si esta ese calendario
        bool Buscar(const TCalendario&) const;

        //Return raiz
        TCalendario Raiz() const;

        //Calendarios segun el recorrido preorden
        TVectorCalendario Preorden() const;
        //Calendarios segun el recorrido inorden
        TVectorCalendario Inorden() const;
        //Calendarios segun el recorrido postorden
        TVectorCalendario Postorden() const;
        //Calendarios segun el recorrido por niveles
        TVectorCalendario Niveles() const;

        //Recorrer de iz a de la lista. Por cada calendario no-vacio:
        //Si no existe en el arbol insertarlo en abb,
        //e insertar en el vector el camino desde la raiz a ese calendario (inclusive)
        //El calendario debe estar lleno
        TVectorCalendario ABBCamino(const TListaCalendario&);

        //Agregar ese calendario
        bool Insertar(const TCalendario&);

        //Eliminar un calendario por su equivalente
        bool Borrar(const TCalendario&);
};

//==========

class TNodoABB{
    friend class TABBCalendario;

    private:
        TCalendario item;
        TABBCalendario iz, de;

    public:
        //Constructor por defecto
        TNodoABB();
        //Constructor de copia
        TNodoABB(const TNodoABB&);
        //Asignacion
        TNodoABB& operator=(const TNodoABB&);
        //Destructor
        ~TNodoABB();
};

#endif