#include "tavlcalendario.h"
#include <cstdlib>
#include <queue>


TNodoAVL::TNodoAVL():
    item(TCalendario()), iz(TAVLCalendario()), de(TAVLCalendario()), fe(0){}


TNodoAVL::TNodoAVL(const TNodoAVL& other_nodo):
    item(other_nodo.item), iz(other_nodo.iz), de(other_nodo.de), fe(other_nodo.fe){}


TNodoAVL& TNodoAVL::operator=(const TNodoAVL& other_nodo){
    item = other_nodo.item;
    iz = other_nodo.iz;
    de = other_nodo.de;
    fe = other_nodo.fe;
    return *this;
}


TNodoAVL::~TNodoAVL(){}

//==========

std::ostream& operator<<(std::ostream& os, const TAVLCalendario& AVL){
    os <<AVL.Inorden();
    return os;
}


TAVLCalendario::TAVLCalendario():
    raiz(NULL){}


TAVLCalendario::TAVLCalendario(const TAVLCalendario& other_avl){
    raiz = NULL;
    *this = other_avl;
}


TAVLCalendario& TAVLCalendario::operator=(const TAVLCalendario& other_avl){
    if (raiz != NULL){
        delete raiz;
        raiz = NULL;
    }

    if (other_avl.raiz != NULL){
        TNodoAVL* nodo_new = new TNodoAVL();
        *nodo_new = *other_avl.raiz;
        raiz = nodo_new;
    }

    return *this;
}


TAVLCalendario::~TAVLCalendario(){
    if (raiz != NULL){
        delete raiz;
        raiz = NULL;
    }
}


TAVLCalendario TAVLCalendario::operator+(const TAVLCalendario& other_avl) const{
    TAVLCalendario avl_merge = *this;
    TVectorCalendario other_vector = other_avl.Inorden();
    for (unsigned i=1; i<=other_vector.Tamano(); i++)
        avl_merge.Insertar(other_vector[i]);
    return avl_merge;
}


TAVLCalendario TAVLCalendario::operator-(const TAVLCalendario& other_avl) const{
    TAVLCalendario avl_merge;
    TVectorCalendario this_vector = Inorden();
    for (unsigned i=1; i<=this_vector.Tamano(); i++)
        if (!other_avl.Buscar(this_vector[i]))
            avl_merge.Insertar(this_vector[i]);
    return avl_merge;

    /*
    TAVLCalendario avl_merge = *this;
    TVectorCalendario other_vector = other_avl.Inorden();
    for (unsigned i=1; i<=other_vector.Tamano(); i++)
        avl_merge.Borrar(other_vector[i]);
    return avl_merge;
    */
}


bool TAVLCalendario::operator==(const TAVLCalendario& other_avl) const{
    return this->Inorden() == other_avl.Inorden();

    /*
    //Considerando la estructura interna
    if (EsVacio() != !other_avl.EsVacio())
        return false;

    if (raiz->item != other_avl.raiz->item)
        return false;

    return raiz->iz==other_avl.raiz->iz && raiz->de==other_avl.raiz->de;
    */
}


bool TAVLCalendario::operator!=(const TAVLCalendario& other_avl) const{
    return !(*this == other_avl);
}


bool TAVLCalendario::EsVacio() const{
    return raiz == NULL;
}


bool TAVLCalendario::Buscar(const TCalendario& calendario) const{
    if (raiz == NULL)
        return false;

    if (calendario == raiz->item)
        return true;

    if (calendario < raiz->item)
        return raiz->iz.Buscar(calendario);
    else
        return raiz->de.Buscar(calendario);
}


TCalendario TAVLCalendario::Raiz() const{
    return raiz->item;
}


int TAVLCalendario::Altura() const{
    if (raiz == NULL)
        return 0;

    int altura_iz = raiz->iz.Altura();
    int altura_de = raiz->de.Altura();

    if (altura_iz > altura_de)
        return ++altura_iz;
    else
        return ++altura_de;
}


int TAVLCalendario::Nodos() const{
    if (raiz == NULL)
        return 0;

    return raiz->iz.Nodos() + raiz->de.Nodos() + 1;
}


int TAVLCalendario::NodosHoja() const{
    if (raiz == NULL)
        return 0;

    if (raiz->iz.EsVacio() && raiz->de.EsVacio())
        return 1;

    return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}


TVectorCalendario TAVLCalendario::Preorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    PreordenAux(vector, i);
    return vector;
}


TVectorCalendario TAVLCalendario::Inorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    InordenAux(vector, i);
    return vector;
}


TVectorCalendario TAVLCalendario::Postorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    PostordenAux(vector, i);
    return vector;
}


TVectorCalendario TAVLCalendario::Niveles() const{
    if (raiz == NULL)
        return TVectorCalendario();

    TVectorCalendario vector(Nodos());
    std::queue<TNodoAVL*> cola;
    cola.push(raiz);

    for (unsigned i=1; !cola.empty(); i++){
        TNodoAVL* nodo = cola.front();
        cola.pop();

        vector[i] = nodo->item;

        if (!nodo->iz.EsVacio())
            cola.push(nodo->iz.raiz);

        if (!nodo->de.EsVacio())
            cola.push(nodo->de.raiz);
    }
    return vector;
}


bool TAVLCalendario::Insertar(const TCalendario& calendario){
    bool crece = false;
    return InsertarAux(calendario, crece);
}


bool TAVLCalendario::Borrar(const TCalendario& calendario){
    bool decrece = false;
    return BorrarAux(calendario, decrece);
}


void TAVLCalendario::PreordenAux(TVectorCalendario& vector, int& i) const{
    vector[i] = raiz->item;
    i++;

    if (!raiz->iz.EsVacio())
        raiz->iz.PreordenAux(vector, i);

    if (!raiz->de.EsVacio())
        raiz->de.PreordenAux(vector, i);
}


void TAVLCalendario::InordenAux(TVectorCalendario& vector, int& i) const{
    if (!raiz->iz.EsVacio())
        raiz->iz.InordenAux(vector, i);

    vector[i] = raiz->item;
    i++;

    if (!raiz->de.EsVacio())
        raiz->de.InordenAux(vector, i);
}


void TAVLCalendario::PostordenAux(TVectorCalendario& vector, int& i) const{
    if (!raiz->iz.EsVacio())
        raiz->iz.PostordenAux(vector, i);

    if (!raiz->de.EsVacio())
        raiz->de.PostordenAux(vector, i);

    vector[i] = raiz->item;
    i++;
}


bool TAVLCalendario::InsertarAux(const TCalendario& calendario, bool& crece){
    bool crece_iz = false;
    bool crece_de = false;
    bool bool_insertado = false;

    if (raiz == NULL){
        TNodoAVL* nodo_new = new TNodoAVL();
        nodo_new->item = calendario;
        raiz = nodo_new;
        crece = true;
        return true;
    }

    if (raiz->item == calendario)
        return false;

    if (calendario < raiz->item)
        bool_insertado = raiz->iz.InsertarAux(calendario, crece_iz);
    else
        bool_insertado = raiz->de.InsertarAux(calendario, crece_de);

    if (!(crece_iz || crece_de)){
        crece = false;
        return bool_insertado;
    }

    if (raiz->fe == -1){
        crece = false;
        if (crece_de)
            raiz->fe = 0;
        else
            EquilibrarIz(true, false);
    }
    else if (raiz->fe == 1){
        crece = false;
        if (crece_iz)
            raiz->fe = 0;
        else
            EquilibrarDe(true, false);
    }
    else{
        crece = true;
        if (crece_iz)
            raiz->fe = -1;
        else
            raiz->fe = 1;
    }

    return bool_insertado;
}


bool TAVLCalendario::BorrarAux(const TCalendario& calendario, bool& decrece){
    bool decrece_iz = false;
    bool decrece_de = false;
    bool bool_borrado = false;

    if (raiz == NULL)
        return false;

    if (raiz->item == calendario){
        if (raiz->iz.EsVacio() && raiz->de.EsVacio()){
            delete raiz;
            raiz = NULL;
            decrece = true;
        }
        else if (raiz->iz.EsVacio()){
            TNodoAVL* aux_del = raiz;
            raiz = raiz->de.raiz;
            free(aux_del);
            decrece = true;
        }
        else if (raiz->de.EsVacio()){
            TNodoAVL* aux_del = raiz;
            raiz = raiz->iz.raiz;
            free(aux_del);
            decrece = true;
        }
        else{
            TNodoAVL* aux = raiz->iz.raiz;
            while (!aux->de.EsVacio())
                aux = aux->de.raiz;
            raiz->item = aux->item;

            bool hijo_borrado = aux == raiz->iz.raiz;
            raiz->iz.Borrar(aux->item);

            if (hijo_borrado){
                if (raiz->fe == -1)
                    raiz->fe = 0;
                else if (raiz->fe == 1)
                    EquilibrarDe(true, true);
                else
                    raiz->fe = 1;
            }
            else{
                raiz->fe = raiz->de.Altura() - raiz->iz.Altura();
                if (raiz->fe == 2){
                    raiz->fe = 1;
                    EquilibrarDe(true, true);
                }
            }
        }
        return true;
    }

    if (calendario < raiz->item)
        bool_borrado = raiz->iz.BorrarAux(calendario, decrece_iz);
    else
        bool_borrado = raiz->de.BorrarAux(calendario, decrece_de);

    if (!(decrece_iz || decrece_de)){
        decrece = false;
        return bool_borrado;
    }
    if (raiz->fe == -1){
        if (decrece_iz)
            raiz->fe = 0;
        else
            EquilibrarIz(true, true);
    }
    else if (raiz->fe == 1){
        if (decrece_de)
            raiz->fe = 0;
        else
            EquilibrarDe(true, true);
    }
    else{
        if (decrece_de)
            raiz->fe = -1;
        else
            raiz->fe = 1;
    }

    decrece = raiz->fe == 0;
    return bool_borrado;
}


void TAVLCalendario::EquilibrarIz(bool permitir_doble, bool from_borrar){
    bool equilibrar_de_tambn = raiz->iz.raiz->fe == 1 && permitir_doble;
    if (equilibrar_de_tambn)
        raiz->iz.EquilibrarDe(false, from_borrar);

    TNodoAVL* aux = raiz->iz.raiz;
    raiz->iz.raiz = aux->de.raiz;
    aux->de.raiz = raiz;
    raiz = aux;

    if (from_borrar && !equilibrar_de_tambn && raiz->fe==0)
        raiz->fe = 1;
    else{
        if (from_borrar)
            raiz->de.raiz->fe = raiz->de.raiz->de.Altura() - raiz->de.raiz->iz.Altura();
        else
            raiz->de.raiz->fe = 0;
        raiz->fe = 0;
    }
}


void TAVLCalendario::EquilibrarDe(bool permitir_doble, bool from_borrar){
    bool equilibrar_iz_tambn = raiz->de.raiz->fe == -1 && permitir_doble;
    if (equilibrar_iz_tambn)
        raiz->de.EquilibrarIz(false, from_borrar);

    TNodoAVL* aux = raiz->de.raiz;
    raiz->de.raiz = aux->iz.raiz;
    aux->iz.raiz = raiz;
    raiz = aux;

    if (from_borrar && !equilibrar_iz_tambn && raiz->fe==0)
        raiz->fe = -1;
    else{
        if (from_borrar)
            raiz->iz.raiz->fe = raiz->iz.raiz->de.Altura() - raiz->iz.raiz->iz.Altura();
        else
            raiz->iz.raiz->fe = 0;
        raiz->fe = 0;
    }
}