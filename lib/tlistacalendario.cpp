#include "tlistacalendario.h"


TNodoCalendario::TNodoCalendario():
    c(TCalendario()), siguiente(NULL){}


TNodoCalendario::TNodoCalendario(const TNodoCalendario& other_nodo):
    c(other_nodo.c), siguiente(other_nodo.siguiente){}


TNodoCalendario& TNodoCalendario::operator=(const TNodoCalendario& other_nodo){
    c = other_nodo.c;
    siguiente = other_nodo.siguiente;
    return *this;
}


TNodoCalendario::~TNodoCalendario(){
    siguiente = NULL;
}

//==========

TListaPos::TListaPos():
    pos(NULL){}


TListaPos::TListaPos(const TListaPos& other_pos):
    pos(other_pos.pos){}


TListaPos& TListaPos::operator=(const TListaPos& other_pos){
    pos = other_pos.pos;
    return *this;
}


TListaPos::~TListaPos(){
    pos = NULL;
}


bool TListaPos::operator==(const TListaPos& other_pos) const{
    return pos->siguiente == other_pos.pos->siguiente;
}


bool TListaPos::operator!=(const TListaPos& other_pos) const{
    return !(*this == other_pos);
}


TListaPos TListaPos::Siguiente() const{
    TListaPos pos_siguiente;
    pos_siguiente.pos = pos->siguiente;
    return pos_siguiente;
}


bool TListaPos::EsVacia() const{
    return pos == NULL;
}

//==========

std::ostream& operator<<(std::ostream& os, const TListaCalendario& lista){
    os <<"<";
    for (TListaPos i_pos=lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        if (!i_pos.Siguiente().EsVacia())
            os <<lista.Obtener(i_pos)<< " ";
        else
            os <<lista.Obtener(i_pos);
    os <<">";

    return os;
}


TListaCalendario::TListaCalendario():
    primero(NULL){}


TListaCalendario::TListaCalendario(const TListaCalendario& other_lista){
    primero = NULL;
    for (TListaPos i_pos=other_lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        Insertar(other_lista.Obtener(i_pos));
}


TListaCalendario& TListaCalendario::operator=(const TListaCalendario& other_lista){
    if (!other_lista.EsVacia()){
        TListaPos i_pos = Primera();
        TListaPos aux;

        while(!i_pos.EsVacia()){
            aux = i_pos;
            i_pos = i_pos.Siguiente();
            delete aux.pos;
        }
        primero = NULL;

        for (TListaPos i_pos=other_lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
            Insertar(other_lista.Obtener(i_pos));
    }
    return *this;
}


TListaCalendario::~TListaCalendario(){
    TListaPos i_pos = Primera();
    TListaPos aux;

    while(!i_pos.EsVacia()){
        aux = i_pos;
        i_pos = i_pos.Siguiente();
        delete aux.pos;
    }
    primero = NULL;
}


TListaCalendario TListaCalendario::operator+(const TListaCalendario& other_lista) const{
    TListaCalendario lista_merge = *this;
    for (TListaPos i_pos=other_lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        lista_merge.Insertar(other_lista.Obtener(i_pos));
    return lista_merge;
}


TListaCalendario TListaCalendario::operator-(const TListaCalendario& other_lista) const{
    TListaCalendario lista_merge = *this;
    for (TListaPos i_pos=other_lista.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        lista_merge.Borrar(other_lista.Obtener(i_pos));
    return lista_merge;
}


bool TListaCalendario::operator==(const TListaCalendario& other_lista) const{
    if (Longitud() != other_lista.Longitud())
        return false;

    TListaPos i_pos_this = Primera();
    TListaPos i_pos_other = other_lista.Primera();
    for (unsigned i=0; i<Longitud(); i++){
        if (i_pos_this.pos->c != i_pos_other.pos->c)
            return false;

        i_pos_this.Siguiente();
        i_pos_other.Siguiente();
    }

    return true;
}


int TListaCalendario::Longitud() const{
    int cont = 0;
    for (TListaPos i_pos=Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        cont++;
    return cont;
}


bool TListaCalendario::EsVacia() const{
    return primero == NULL;
}


bool TListaCalendario::Buscar(const TCalendario& calendario) const{
    for (TListaPos i_pos=Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())
        if (i_pos.pos->c == calendario)
            return true;

    return false;
}


TListaPos TListaCalendario::Primera() const{
    TListaPos pos;
    pos.pos = primero;
    return pos;
}


TListaPos TListaCalendario::Ultima() const{
    TListaPos pos = Primera();
    if (!pos.EsVacia())
        while (!pos.Siguiente().EsVacia())
            pos=pos.Siguiente();

    return pos;
}


TCalendario TListaCalendario::Obtener(const TListaPos& pos) const{
    if (pos.EsVacia())
        return TCalendario();

    return pos.pos->c;
}


//El borrado directo da problemas. Solucionado con las lineas que contienen "//" al final
TListaCalendario TListaCalendario::ExtraerRango(int n1, int n2){
    TListaCalendario lista_extraida;

    int i = 1;
    for (TListaPos i_pos=Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente()){
        if (n1<=i && i<=n2){
            TCalendario calendario = Obtener(i_pos);
            lista_extraida.Insertar(calendario);
            //Borrar(calendario);
        }
        i++;
    }

    for (TListaPos i_pos=lista_extraida.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente())//
        Borrar(lista_extraida.Obtener(i_pos));//

    return lista_extraida;
}


TListaCalendario TListaCalendario::SumarSubl(int I_L1, int F_L1, TListaCalendario& L2, int I_L2, int F_L2) const{
    int i;
    TListaCalendario lista_merge;

    i = 1;
    for (TListaPos i_pos=Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente()){
        if (I_L1<=i && i<=F_L1)
            lista_merge.Insertar(Obtener(i_pos));
        i++;
    }

    i = 1;
    for (TListaPos i_pos=L2.Primera(); !i_pos.EsVacia(); i_pos=i_pos.Siguiente()){
        if (I_L2<=i && i<=F_L2)
            lista_merge.Insertar(L2.Obtener(i_pos));
        i++;
    }

    return lista_merge;
}


bool TListaCalendario::Insertar(const TCalendario& calendario){
    TNodoCalendario* nodo_new = new TNodoCalendario();
    nodo_new->c = calendario;

    TNodoCalendario* p2 = primero;
    TNodoCalendario* p1;

    while (p2!=NULL && !(p2->c>calendario)){
        p1 = p2;
        p2 = p2->siguiente;
    }

    if (p2 == primero){
        if (p2==NULL || p2->c!=calendario)
            primero = nodo_new;
        else{
            delete nodo_new;
            return false;
        }
    }
    else if (p1->c == calendario){
        delete nodo_new;
        return false;
    }
    else
        p1->siguiente = nodo_new;

    nodo_new->siguiente = p2;
    return true;
}


bool TListaCalendario::Borrar(const TCalendario& calendario){
    TNodoCalendario* p2 = primero;
    TNodoCalendario* p1;

    while (p2!=NULL && p2->c!=calendario){
        p1 = p2;
        p2 = p2->siguiente;
    }

    if (p2 == NULL)
        return false;

    TNodoCalendario* aux_del;
    if (p2 == primero){
        aux_del = primero;
        primero = primero->siguiente;
    }
    else{
        aux_del = p1->siguiente;
        p1->siguiente = p2->siguiente;
    }
    delete aux_del;

    return true;
}


bool TListaCalendario::Borrar(const TListaPos& pos){
    if (pos.EsVacia())
        return false;

    Borrar(pos.pos->c);
    return true;
}


//El borrado de memoria directo da problemas. Solucionado con las lineas que contienen "//" al final
bool TListaCalendario::Borrar(int dia, int mes, int anyo){
    TCalendario calendario_max = TCalendario(dia, mes, anyo, NULL);

    TNodoCalendario* p2 = primero;
    TNodoCalendario* p1;

    TNodoCalendario** fix_del = new TNodoCalendario*[Longitud()];//
    unsigned size_fix_del = 0;//

    bool is_eliminado = false;

    while (p2!=NULL){
        calendario_max.ModMensaje(p2->c.Mensaje());
        if (p2->c < calendario_max){
            TNodoCalendario* aux_del;
            if (p2 == primero){
                aux_del = primero;
                primero = primero->siguiente;
            }
            else{
                aux_del = p1->siguiente;
                p1->siguiente = p2->siguiente;
            }
            //delete aux_del;
            fix_del[size_fix_del] = aux_del;//
            size_fix_del++;//
            is_eliminado = true;
        }
        else
            p1 = p2;

        p2 = p2->siguiente;
    }

    for (unsigned i=0; i<size_fix_del; i++){//
        delete fix_del[i];//
        fix_del[i] = NULL;//
    }//
    delete[] fix_del;//
    fix_del = NULL;//

    return is_eliminado;
}