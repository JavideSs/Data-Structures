#include "tvectorcalendario.h"


std::ostream& operator<<(std::ostream& os, const TVectorCalendario& vector){
    os <<"[";
    unsigned i;
    for (i=1; i<vector.Tamano(); i++)
        os <<"("<<i<<") "<<vector[i]<<", ";
    if (vector.Tamano() != 0)
        os <<"("<<i<<") "<<vector[i];
    os<<"]";

    return os;
}


TVectorCalendario::TVectorCalendario():
    tamano(0), c(NULL), error(TCalendario()){}


TVectorCalendario::TVectorCalendario(int tamano):
    error(TCalendario()){

    if (tamano > 0){
        this->tamano = tamano;
        c = new TCalendario[tamano];
    }
    else{
        this->tamano = 0;
        c = NULL;
    }
}


TVectorCalendario::TVectorCalendario(const TVectorCalendario& other_vector):
    tamano(other_vector.Tamano()), error(TCalendario()){

    if (other_vector.Tamano() == 0)
        c = NULL;
    else{
        c = new TCalendario[other_vector.Tamano()];
        for (unsigned i=1; i<=other_vector.Tamano(); i++)
            (*this)[i] = other_vector[i];
    }
}


TVectorCalendario& TVectorCalendario::operator=(const TVectorCalendario& other_vector){
    tamano = other_vector.Tamano();
    error = TCalendario();

    if (c != NULL){
        delete[] c;
        c = NULL;
    }

    if (other_vector.Tamano() != 0){
        c = new TCalendario[other_vector.Tamano()];
        for (unsigned i=1; i<=other_vector.Tamano(); i++)
            (*this)[i] = other_vector[i];
    }

    return *this;
}


TVectorCalendario::~TVectorCalendario(){
    tamano = 0;

    if (c != NULL){
        delete[] c;
        c = NULL;
    }
}


//other_vector[i] devuelve nueva copia porque other_vector es const
//(*this)[i] devuelve nueva copia porque metodo es const
bool TVectorCalendario::operator==(const TVectorCalendario& other_vector) const{
    if (tamano != other_vector.Tamano())
        return false;

    for (unsigned i=1; i<=tamano; i++)
        if ((*this)[i] != other_vector[i])
            return false;

    return true;
}


bool TVectorCalendario::operator!=(const TVectorCalendario& other_vector) const{
    return !(*this == other_vector);
}


TCalendario& TVectorCalendario::operator[](int i){
    if (i>=1 && i-1<tamano)
        return c[i-1];
    else
        return error;
}


TCalendario TVectorCalendario::operator[](int i) const{
    if (i>=1 && i-1<tamano)
        return c[i-1];
    else
        return error;
}


bool TVectorCalendario::Redimensionar(int n){
    if (n<=0 || n==tamano)
        return false;

    TCalendario* c_aux = new TCalendario[n];
    for (unsigned i=0; i<tamano && i<n; i++)
        c_aux[i] = c[i];

    delete[] c;
    c = c_aux;
    tamano = n;

    return true;
}


int TVectorCalendario::Ocupadas() const{
    unsigned ocupadas = 0;
    for (unsigned i=1; i<=tamano; i++)
        if (!(*this)[i].EsVacio())
            ocupadas++;

    return ocupadas;
}


bool TVectorCalendario::ExisteCal(const TCalendario& calendario) const{
    for (unsigned i=1; i<=tamano; i++)
        if ((*this)[i] == calendario)
            return true;

    return false;
}


void TVectorCalendario::MostrarMensajes(int dia, int mes, int anyo) const{
    TCalendario calendario_min = TCalendario(dia, mes, anyo, NULL);

    std::cout <<"[";
    int aux_print = false;
    for (unsigned i=1; i<=tamano; i++){
        calendario_min.ModMensaje((*this)[i].Mensaje());
        if (!((*this)[i] < calendario_min)){
            if (!aux_print)
                aux_print = true;
            else
                std::cout <<", ";
            std::cout <<(*this)[i];
        }
    }
    std::cout <<"]";
}