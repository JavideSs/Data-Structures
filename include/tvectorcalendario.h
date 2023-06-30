#ifndef _TVECTORCALENDARIO_
    #define _TVECTORCALENDARIO_

#include <iostream>
#include "tcalendario.h"


class TVectorCalendario{
    //Salida
    friend std::ostream& operator<<(std::ostream&, const TVectorCalendario&);

    private:
        int tamano;
        TCalendario *c;
        TCalendario error;

    public:
        //Constructor por defecto
        TVectorCalendario();
        //Constructor por parametros
        TVectorCalendario(int tamano);
        //Constructor de copia
        TVectorCalendario(const TVectorCalendario&);
        //Asignacion
        TVectorCalendario& operator=(const TVectorCalendario&);
        //Destructor
        ~TVectorCalendario();

        //Igualdad
        bool operator==(const TVectorCalendario&) const;
        //Desigualdad
        bool operator!=(const TVectorCalendario&) const;
        //Corchete set-get
        TCalendario& operator[](int);
        //Corchete get con this const
        TCalendario operator[](int) const;

        //Return tamano
        inline int Tamano() const { return tamano;}

        //Realloc this
        bool Redimensionar(int);
        //Numero de posiciones no vacias
        int Ocupadas() const;
        //Si esta ese calendario
        bool ExisteCal(const TCalendario&) const;
        //Print mensajes de calendarios con fecha igual o superior a esa
        void MostrarMensajes(int dia, int mes, int anyo) const;
};

#endif