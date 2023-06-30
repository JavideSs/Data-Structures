#ifndef _TCALENDARIO_
    #define _TCALENDARIO_

#include <iostream>


class TCalendario{
    //Salida
    friend std::ostream& operator<<(std::ostream&, const TCalendario&);

    private:
        int dia, mes, anyo;
        char* mensaje;

        //Es fecha
        bool esFecha(int dia, int mes, int anyo) const;
        //Es fecha
        bool esFecha(const TCalendario&) const;

    public:
        //Constructor por defecto
        TCalendario();
        //Constructor por parametros
        TCalendario(int dia, int mes, int anyo, const char*);
        //Constructor de copia
        TCalendario(const TCalendario&);
        //Asignacion
        TCalendario& operator=(const TCalendario&);
        //Destructor
        ~TCalendario();

        //PreIncrementar un dia a la fecha, return this
        TCalendario& operator++();
        //PreDecrementar un dia a la fecha, return this
        TCalendario& operator--();
        //PostIncrementar un dia a la fecha, return copia
        TCalendario operator++(int);
        //PostDecrementar un dia a la fecha, return copia
        TCalendario operator--(int);
        //Incrementar un numero de dias a la fecha, return copia
        TCalendario operator+(int) const;
        //Decrementar un numero de dias a la fecha, return copia
        TCalendario operator-(int) const;

        //Igualdad
        bool operator==(const TCalendario&) const;
        //Desigualdad
        bool operator!=(const TCalendario&) const;
        //Mayor this
        bool operator>(const TCalendario&) const;
        //Menor this
        bool operator<(const TCalendario&) const;

        //Return dia
        inline int Dia() const { return dia;}
        //Return mes
        inline int Mes() const { return mes;}
        //Return anyo
        inline int Anyo() const { return anyo;}
        //Return mensaje
        inline char* Mensaje() const { return mensaje;}

        //Modificar fecha
        bool ModFecha(int dia, int mes, int anyo);
        //Modificar mensaje
        bool ModMensaje(const char*);
        //Si this vacio
        bool EsVacio() const;
};

#endif