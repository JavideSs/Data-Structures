#ifndef _TAVLCALENDARIO_
    #define _TAVLCALENDARIO_

#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"


class TNodoAVL;

class TAVLCalendario{
    //Salida
    friend std::ostream& operator<<(std::ostream&, const TAVLCalendario&);

    private:
        TNodoAVL* raiz;

        //Aux de "Preorden()"
        void PreordenAux(TVectorCalendario&, int& i) const;
        //Aux de "Inorden()"
        void InordenAux(TVectorCalendario&, int& i) const;
        //Aux de "Postorden()"
        void PostordenAux(TVectorCalendario&, int& i) const;
        //Aux de "Insertar()"

        bool InsertarAux(const TCalendario&, bool& crece);
        //Aux de "Borrar()"
        bool BorrarAux(const TCalendario&, bool& crece);

        //Equilibrar por rotacion a la izquierda
        void EquilibrarIz(bool permitir_doble, bool from_borrar);
        //Equilibrar por rotacion a la derecha
        void EquilibrarDe(bool permitir_doble, bool from_borrar);

    public:
        //Constructor por defecto
        TAVLCalendario();
        //Constructor de copia
        TAVLCalendario(const TAVLCalendario&);
        //Asignacion
        TAVLCalendario& operator=(const TAVLCalendario&);
        //Destructor
        ~TAVLCalendario();

        //Incrementar
        TAVLCalendario operator+(const TAVLCalendario&) const;
        //Decrementar
        TAVLCalendario operator-(const TAVLCalendario&) const;

        //Igualdad
        bool operator==(const TAVLCalendario&) const;
        //Desigualdad
        bool operator!=(const TAVLCalendario&) const;

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

        //Agregar ese calendario
        bool Insertar(const TCalendario&);

        //Eliminar un calendario por su equivalente
        bool Borrar(const TCalendario&);
};

//==========

class TNodoAVL{
    friend class TAVLCalendario;

    private:
        TCalendario item;
        TAVLCalendario iz, de;
        int fe;

    public:
        //Constructor por defecto
        TNodoAVL();
        //Constructor de copia
        TNodoAVL(const TNodoAVL&);
        //Asignacion
        TNodoAVL& operator=(const TNodoAVL&);
        //Destructor
        ~TNodoAVL();
};

#endif