#ifndef _TLISTAPOS_
    #define _TLISTAPOS_

#include <iostream>
#include "tcalendario.h"


class TNodoCalendario{
    friend class TListaPos;
    friend class TListaCalendario;

    private:
        TCalendario c;
        TNodoCalendario* siguiente;

    public:
        //Constructor por defecto
        TNodoCalendario();
        //Constructor de copia
        TNodoCalendario(const TNodoCalendario&);
        //Asignacion
        TNodoCalendario& operator=(const TNodoCalendario&);
        //Destructor
        ~TNodoCalendario();
};

//==========

class TListaPos{
    friend class TListaCalendario;

    private:
        TNodoCalendario* pos;

    public:
        //Constructor por defecto
        TListaPos();
        //Constructor de copia
        TListaPos(const TListaPos&);
        //Asignacion
        TListaPos& operator=(const TListaPos&);
        //Destructor
        ~TListaPos();

        //Igualdad
        bool operator==(const TListaPos&) const;
        //Desigualdad
        bool operator!=(const TListaPos&) const;

        //Posicion siguiente
        TListaPos Siguiente() const;
        //Si this vacio
        bool EsVacia() const;
};

//==========

class TListaCalendario{
    //Salida
    friend std::ostream& operator<<(std::ostream&, const TListaCalendario&);

    private:
        TNodoCalendario* primero;

    public:
        //Constructor por defecto
        TListaCalendario();
        //Constructor de copia
        TListaCalendario(const TListaCalendario&);
        //Asignacion
        TListaCalendario& operator=(const TListaCalendario&);
        //Destructor
        ~TListaCalendario();

        //Incrementar
        TListaCalendario operator+(const TListaCalendario&) const;
        //Decrementar
        TListaCalendario operator-(const TListaCalendario&) const;

        //Igualdad
        bool operator==(const TListaCalendario&) const;

        //Numero de calendarios
        int Longitud() const;
        //Si ningun calendario existe
        bool EsVacia() const;

        //Si esta ese calendario
        bool Buscar(const TCalendario&) const;

        //Primera posicion
        TListaPos Primera() const;
        //Ultima posicion
        TListaPos Ultima() const;
        //Calendario en esa posicion
        TCalendario Obtener(const TListaPos&) const;
        //Calendarios en ese rango, se eliminan de this
        TListaCalendario ExtraerRango(int, int);

        //Calendarios de this en ese rango y los calendarios de esa lista en ese otro rango
        TListaCalendario SumarSubl(int, int, TListaCalendario&, int, int) const;

        //Agregar ese calendario en orden
        bool Insertar(const TCalendario&);

        //Eliminar un calendario por su equivalente
        bool Borrar(const TCalendario&);
        //Eliminar calendario en esa posicion
        bool Borrar(const TListaPos&);
        //Eliminar calendarios con fecha menor a esa
        bool Borrar(int dia, int mes, int anyo);
};

#endif