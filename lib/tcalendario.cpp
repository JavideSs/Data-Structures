#include "tcalendario.h"
#include <cstring>
#include <cstdio>


std::ostream& operator<<(std::ostream& os, const TCalendario& calendario){
    char date[13];
    std::sprintf(date, "%02d/%02d/%d",
        calendario.Dia(),
        calendario.Mes(),
        calendario.Anyo());

    os <<date<<" \"";
    if (calendario.Mensaje() == NULL)   os<<"\"";
    else                                os<<calendario.Mensaje()<<"\"";

    return os;
}


TCalendario::TCalendario():
    dia(1), mes(1), anyo(1900), mensaje(NULL){}


TCalendario::TCalendario(int dia, int mes, int anyo, const char* mens){
    if (esFecha(dia, mes, anyo)){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;

        if (mens == NULL)
            mensaje = NULL;
        else{
            mensaje = new char[strlen(mens)+1];
            strcpy(mensaje, mens);
        }
    }
    else{
        this->dia = 1;
        this->mes = 1;
        this->anyo = 1900;
        mensaje = NULL;
    }
}


TCalendario::TCalendario(const TCalendario& other_calendario):
    dia(other_calendario.Dia()),
    mes(other_calendario.Mes()),
    anyo(other_calendario.Anyo()){

    if (other_calendario.Mensaje() == NULL)
        mensaje = NULL;
    else{
        char* other_mensaje = other_calendario.Mensaje();
        mensaje = new char[strlen(other_mensaje)+1];
        strcpy(mensaje, other_mensaje);
    }
}


TCalendario& TCalendario::operator=(const TCalendario& other_calendario){
    dia = other_calendario.Dia();
    mes = other_calendario.Mes();
    anyo = other_calendario.Anyo();

    if (mensaje != NULL){
        delete[] mensaje;
        mensaje = NULL;
    }

    if (other_calendario.Mensaje() != NULL){
        const char* other_mensaje = other_calendario.Mensaje();
        mensaje = new char[strlen(other_mensaje)+1];
        strcpy(mensaje, other_mensaje);
    }

    return *this;
}


TCalendario::~TCalendario(){
    dia = 1;
    mes = 1;
    anyo = 1900;

    if (mensaje != NULL){
        delete[] mensaje;
        mensaje = NULL;
    }
}


TCalendario& TCalendario::operator++(){
    dia++;
    if (esFecha(*this))
        return *this;

    dia = 1; mes++;
    if (esFecha(*this))
        return *this;

    mes = 1; anyo++;
    return *this;

    /*
    dia++;
    if(!esFecha(*this)){
        dia = 1; mes++;
    }
    if(!esFecha(*this)){
        mes = 1; anyo++;
    }
    return *this;
    */
}


TCalendario& TCalendario::operator--(){
    dia--;
    if (esFecha(*this))
        return *this;

    mes--;
    for (unsigned i=31; i<28; i--){
        dia = i;
        if(esFecha(*this))
            return *this;
    }

    dia = 31; mes = 12; anyo--;
    if (esFecha(*this))
        return *this;

    dia = 1; mes = 1; anyo = 1900;
    delete[] mensaje; mensaje = NULL;
    return *this;

    /*
    dia--;
    if (!esFecha(*this)){
        mes--;
        for(unsigned i=31; i<28; i--){
            dia = i;
            if(esFecha(*this))
                return *this;
        }
    }
    if (!esFecha(*this)){
        dia = 31; mes = 12; anyo--;
    }
    if (!esFecha(*this))
        dia = 1; mes = 1; anyo = 1900;
    return *this;
    */
}


TCalendario TCalendario::operator++(int){
    TCalendario calendario_new = *this;
    ++(*this);
    return calendario_new;
}


TCalendario TCalendario::operator--(int){
    TCalendario calendario_new = *this;
    --(*this);
    return calendario_new;
}


TCalendario TCalendario::operator+(int incr) const{
    TCalendario calendario_new = *this;
    for (int i=0; i<incr; i++)
        ++calendario_new;
    return calendario_new;
}


TCalendario TCalendario::operator-(int incr) const{
    TCalendario calendario_new = *this;
    for (int i=0; i<incr; i++)
        --calendario_new;
    return calendario_new;
}


bool TCalendario::operator==(const TCalendario& other_calendario) const{
    if (dia==other_calendario.Dia()
    && mes==other_calendario.Mes()
    && anyo==other_calendario.Anyo()){
        if (mensaje==NULL && other_calendario.Mensaje()==NULL)
            return true;
        if (mensaje==NULL || other_calendario.Mensaje()==NULL)
            return false;
        else
            return (strcmp(mensaje, other_calendario.mensaje)==0);
    }
    else
        return false;
}


bool TCalendario::operator!=(const TCalendario& other_calendario) const{
    return !(*this == other_calendario);
}


bool TCalendario::operator>(const TCalendario& other_calendario) const{
    if (anyo > other_calendario.Anyo())
        return true;
    if (anyo < other_calendario.Anyo())
        return false;

    if (mes > other_calendario.Mes())
        return true;
    if (mes < other_calendario.Mes())
        return false;

    if (dia > other_calendario.Dia())
        return true;
    if (dia < other_calendario.Dia())
        return false;

    if (mensaje == NULL)
        return false;
    if (other_calendario.mensaje == NULL)
        return true;

    return strcmp(mensaje, other_calendario.mensaje)>0;
}


bool TCalendario::operator<(const TCalendario& other_calendario) const{
    return !(*this>other_calendario || *this==other_calendario);
}


bool TCalendario::ModFecha(int dia, int mes, int anyo){
    if (esFecha(dia, mes, anyo)){
        this->dia = dia;
        this->mes = mes;
        this->anyo = anyo;
        return true;
    }
    else
        return false;
}


bool TCalendario::ModMensaje(const char* mens){
    try{
        if (mensaje != NULL){
            delete[] mensaje;
            mensaje = NULL;
        }

        if (mens == NULL)
            mensaje = NULL;
        else{
            mensaje= new char[strlen(mens)+1];
            strcpy(mensaje, mens);
        }

        return true;
    }
    catch (std::bad_alloc&){
        return false;
    }
}


bool TCalendario::EsVacio() const{
    return (dia==1 && mes==1 && anyo==1900 && mensaje==NULL);
}


bool TCalendario::esFecha(int dia, int mes, int anyo) const{
    if (anyo >= 1900){
        if (mes<1 || mes>12)
            return false;

        else{
            if (mes==2){
                if ((anyo%4==0 && anyo%100!=0) || (anyo%4==0 && anyo%100==0 && anyo%400==0)){
                    if (dia>=1 && dia<=29)
                        return true;
                }
                else{
                    if (dia>=1 && dia<=28)
                        return true;
                }
            }
            else if (mes==4 || mes==6 || mes==9 || mes==11){
                if (dia>=1 && dia<=30)
                    return true;
            }
            else{
                if (dia>=1 && dia<=31)
                    return true;
            }
        }
    }
    return false;
}


bool TCalendario::esFecha(const TCalendario& calendario) const{
    return esFecha(calendario.Dia(), calendario.Mes(), calendario.Anyo());
}