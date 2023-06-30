#include "tabbcalendario.h"
#include <cstdlib>
#include <queue>


TNodoABB::TNodoABB():
    item(TCalendario()), iz(TABBCalendario()), de(TABBCalendario()){}


TNodoABB::TNodoABB(const TNodoABB& other_nodo):
    item(other_nodo.item), iz(other_nodo.iz), de(other_nodo.de){}


TNodoABB& TNodoABB::operator=(const TNodoABB& other_nodo){
    item = other_nodo.item;
    iz = other_nodo.iz;
    de = other_nodo.de;
    return *this;
}


TNodoABB::~TNodoABB(){}

//==========

std::ostream& operator<<(std::ostream& os, const TABBCalendario& abb){
    os <<abb.Niveles();
    return os;
}


TABBCalendario::TABBCalendario():
    raiz(NULL){}


TABBCalendario::TABBCalendario(const TABBCalendario& other_abb){
    raiz = NULL;
    *this = other_abb;
}


TABBCalendario& TABBCalendario::operator=(const TABBCalendario& other_abb){
    if (raiz != NULL){
        delete raiz;
        raiz = NULL;
    }

    if (other_abb.raiz != NULL){
        TNodoABB* nodo_new = new TNodoABB();
        *nodo_new = *other_abb.raiz;
        raiz = nodo_new;
    }

    return *this;
}


TABBCalendario::~TABBCalendario(){
    if (raiz != NULL){
        delete raiz;
        raiz = NULL;
    }
}


TABBCalendario TABBCalendario::operator+(const TABBCalendario& other_abb) const{
    TABBCalendario abb_merge = *this;
    TVectorCalendario other_vector = other_abb.Inorden();
    for (unsigned i=1; i<=other_vector.Tamano(); i++)
        abb_merge.Insertar(other_vector[i]);
    return abb_merge;
}


TABBCalendario TABBCalendario::operator-(const TABBCalendario& other_abb) const{
    TABBCalendario abb_merge;
    TVectorCalendario this_vector = Inorden();
    for (unsigned i=1; i<=this_vector.Tamano(); i++)
        if (!other_abb.Buscar(this_vector[i]))
            abb_merge.Insertar(this_vector[i]);
    return abb_merge;

    /*
    TABBCalendario abb_merge = *this;
    TVectorCalendario other_vector = other_abb.Inorden();
    for (unsigned i=1; i<=other_vector.Tamano(); i++)
        abb_merge.Borrar(other_vector[i]);
    return abb_merge;
    */
}


bool TABBCalendario::operator==(const TABBCalendario& other_abb) const{
    return this->Inorden() == other_abb.Inorden();

    /*
    //Considerando la estructura interna
    if (EsVacio() != !other_abb.EsVacio())
        return false;

    if (raiz->item != other_abb.raiz->item)
        return false;

    return raiz->iz==other_abb.raiz->iz && raiz->de==other_abb.raiz->de;
    */
}


bool TABBCalendario::EsVacio() const{
    return raiz == NULL;
}


bool TABBCalendario::Buscar(const TCalendario& calendario) const{
    if (raiz == NULL)
        return false;

    if (calendario == raiz->item)
        return true;

    if (calendario < raiz->item)
        return raiz->iz.Buscar(calendario);
    else
        return raiz->de.Buscar(calendario);
}


TCalendario TABBCalendario::Raiz() const{
    return raiz->item;
}


int TABBCalendario::Altura() const{
    if (raiz == NULL)
        return 0;

    int altura_iz = raiz->iz.Altura();
    int altura_de = raiz->de.Altura();

    if (altura_iz > altura_de)
        return ++altura_iz;
    else
        return ++altura_de;
}


int TABBCalendario::Nodos() const{
    if (raiz == NULL)
        return 0;

    return raiz->iz.Nodos() + raiz->de.Nodos() + 1;
}


int TABBCalendario::NodosHoja() const{
    if (raiz == NULL)
        return 0;

    if (raiz->iz.EsVacio() && raiz->de.EsVacio())
        return 1;

    return raiz->iz.NodosHoja() + raiz->de.NodosHoja();
}


TVectorCalendario TABBCalendario::Preorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    PreordenAux(vector, i);
    return vector;
}


TVectorCalendario TABBCalendario::Inorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    InordenAux(vector, i);
    return vector;
}


TVectorCalendario TABBCalendario::Postorden() const{
    if (raiz == NULL)
        return TVectorCalendario();

    int i = 1;
    TVectorCalendario vector(Nodos());
    PostordenAux(vector, i);
    return vector;
}


TVectorCalendario TABBCalendario::Niveles() const{
    if (raiz == NULL)
        return TVectorCalendario();

    TVectorCalendario vector(Nodos());
    std::queue<TNodoABB*> cola;
    cola.push(raiz);

    for (unsigned i=1; !cola.empty(); i++){
        TNodoABB* nodo = cola.front();
        cola.pop();

        vector[i] = nodo->item;

        if (!nodo->iz.EsVacio())
            cola.push(nodo->iz.raiz);

        if (!nodo->de.EsVacio())
            cola.push(nodo->de.raiz);
    }
    return vector;
}


//Metodo creado en examen. No fiarse
TVectorCalendario TABBCalendario::ABBCamino(const TListaCalendario& lista){
    TVectorCalendario vector;

    if (EsVacio())
        return vector;

    for (TListaPos i_pos=lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente()){
        TCalendario calendario = lista.Obtener(i_pos);

        if (!calendario.EsVacio() && !Buscar(calendario)){
            Insertar(calendario);

            TVectorCalendario vector_camino(Nodos());
            int k = 1;
            TNodoABB* p2 = raiz;
            TNodoABB* p1;

            while (p2!=NULL){
                vector_camino[k] = p2->item;
                k++;
                p1 = p2;
                if (calendario < p2->item)
                    p2 = p2->iz.raiz;
                else if (calendario > p2->item)
                    p2 = p2->de.raiz;
                else
                    break;
            }

            int vector_len = vector.Tamano();
            vector.Redimensionar(vector_len + vector_camino.Ocupadas());

            int i = vector_len+1;
            for (int j=1; j<=vector_camino.Ocupadas(); j++){
                vector[i] = vector_camino[j];
                i++;
            }
        }
    }
    return vector;
}


bool TABBCalendario::Insertar(const TCalendario& calendario){
    if (raiz == NULL){
        TNodoABB* nodo_new = new TNodoABB();
        nodo_new->item = calendario;
        raiz = nodo_new;
        return true;
    }

    if (raiz->item == calendario)
        return false;

    if (calendario < raiz->item)
        return raiz->iz.Insertar(calendario);
    else
        return raiz->de.Insertar(calendario);

    /*
    //Modo Iterativo
    TNodoABB* nodo_new = new TNodoABB();
    nodo_new->item = calendario;

    if (raiz == NULL){
        raiz = nodo_new;
        return true;
    }

    TNodoABB* p2 = raiz;
    TNodoABB* p1;

    while (p2!=NULL){
        p1 = p2;
        if (calendario < p2->item)
            p2 = p2->iz.raiz;
        else if (calendario > p2->item)
            p2 = p2->de.raiz;
        else{
            delete nodo_new;
            return false;
        }
    }

    if (calendario < p1->item)
        p1->iz.raiz = nodo_new;
    else if (calendario > p1->item)
        p1->de.raiz = nodo_new;

    return true;
    */
}


bool TABBCalendario::Borrar(const TCalendario& calendario){
    if (raiz == NULL)
        return false;

    if (raiz->item == calendario){
        if (raiz->iz.EsVacio() && raiz->de.EsVacio()){
            delete raiz;
            raiz = NULL;
        }
        else if (raiz->iz.EsVacio()){
            TNodoABB* aux_del = raiz;
            raiz = raiz->de.raiz;
            free(aux_del);
        }
        else if (raiz->de.EsVacio()){
            TNodoABB* aux_del = raiz;
            raiz = raiz->iz.raiz;
            free(aux_del);
        }
        else{
            TNodoABB* aux = raiz->iz.raiz;
            while (!aux->de.EsVacio())
                aux = aux->de.raiz;
            raiz->item = aux->item;
            raiz->iz.Borrar(aux->item);
        }
        return true;
    }

    if (calendario < raiz->item)
        return raiz->iz.Borrar(calendario);
    else
        return raiz->de.Borrar(calendario);

    /*
    //Modo Iterativo
    //El borrado de memoria directo da problemas. Sin solucionar
    TNodoABB* p2 = raiz;
    TNodoABB* p1;

    while (p2!=NULL && p2->item!=calendario){
        p1 = p2;
        if (calendario < p2->item)
            p2 = p2->iz.raiz;
        else
            p2 = p2->de.raiz;
    }

    if (p2 == NULL)
        return false;

    if (p2->iz.EsVacio() || p2->de.EsVacio()){
        TNodoABB* hijo;

        if (p2->iz.EsVacio() && p2->de.EsVacio())
            hijo = NULL;
        else if (p2->iz.EsVacio())
            hijo = p2->de.raiz;
        else
            hijo = p2->iz.raiz;

        if (p2 == raiz)
            raiz = hijo;
        else if (p2 == p1->iz.raiz)
            p1->iz.raiz = hijo;
        else
            p1->de.raiz = hijo;

        //delete p2;
    }
    else{
        TNodoABB* p2_swap = p2->iz.raiz;
        TNodoABB* p1_swap;

        while (!p2_swap->de.EsVacio()){
            p1_swap = p2_swap;
            p2_swap = p2_swap->de.raiz;
        }

        p2->item = p2_swap->item;

        if (p2_swap == p2->iz.raiz)
            p2->iz.raiz = p2_swap->iz.raiz;
        else
            p1_swap->de.raiz = p2_swap->iz.raiz;

        //delete p2_swap;
    }

    return true;
    */
}


void TABBCalendario::PreordenAux(TVectorCalendario& vector, int& i) const{
    vector[i] = raiz->item;
    i++;

    if (!raiz->iz.EsVacio())
        raiz->iz.PreordenAux(vector, i);

    if (!raiz->de.EsVacio())
        raiz->de.PreordenAux(vector, i);
}


void TABBCalendario::InordenAux(TVectorCalendario& vector, int& i) const{
    if (!raiz->iz.EsVacio())
        raiz->iz.InordenAux(vector, i);

    vector[i] = raiz->item;
    i++;

    if (!raiz->de.EsVacio())
        raiz->de.InordenAux(vector, i);
}


void TABBCalendario::PostordenAux(TVectorCalendario& vector, int& i) const{
    if (!raiz->iz.EsVacio())
        raiz->iz.PostordenAux(vector, i);

    if (!raiz->de.EsVacio())
        raiz->de.PostordenAux(vector, i);

    vector[i] = raiz->item;
    i++;
}