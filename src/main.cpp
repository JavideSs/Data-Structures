#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"
#include "tavlcalendario.h"
#include <iostream>

using std::cout;
using std::endl;


int main(){
    {
    TCalendario a;
    TCalendario b(29,2,2000,"hola Mundo! :p");
    TCalendario c(a);
    TCalendario d = c;

    cout <<a<< endl;
    cout <<b<< endl;
    cout <<c<< endl;
    cout <<d<< endl;
    cout <<(a = b)<< endl;
    cout <<"_____________"<< endl;

    cout <<a.EsVacio()<< endl;
    cout <<b.EsVacio()<< endl;
    cout <<c.EsVacio()<< endl;
    cout <<d.EsVacio()<< endl;
    cout <<"_____________"<< endl;

    a.ModFecha(11,2,1901);
    a.ModMensaje("Hola Mundo! xd");

    cout <<a<< endl;
    cout <<a.EsVacio()<< endl;
    cout <<"_____________"<< endl;
    }

    {
    TCalendario a;
    cout <<a<< endl;

    a++;
    ++a;
    cout <<a<< endl;
    a--;
    --a;

    TCalendario b = a+60;
    TCalendario c = a-60;
    TCalendario d = b+(-3);
    TCalendario e = b-(-3);

    cout <<a<< endl;
    cout <<b<< endl;
    cout <<c<< endl;
    cout <<d<< endl;
    cout <<e<< endl;
    cout <<"_____________"<< endl;
    }

    {
    TCalendario a;
    TCalendario b; b++;

    cout <<(a==b)<< endl;
    cout <<(a!=b)<< endl;
    cout <<(a>b)<< endl;
    cout <<(a<b)<< endl;
    cout <<"vector_____________"<< endl;
    }

    //=========================================

    {
    TVectorCalendario a;
    TVectorCalendario b(5);
    TVectorCalendario c(a);
    TVectorCalendario d = c;

    cout <<a<< endl;
    cout <<b<< endl;
    cout <<c<< endl;
    cout <<d<< endl;
    cout <<(a = c)<< endl;
    cout <<"_____________"<< endl;
    }

    {
    TVectorCalendario a(1);
    a[1] = TCalendario(29,2,2000,"ey");
    a[2] = TCalendario(29,2,2000,"ey");
    cout <<a[1]<< endl;
    cout <<a<< endl;
    cout <<"_____________"<< endl;
    }

    {
    TVectorCalendario a;
    TVectorCalendario b(2);
    TVectorCalendario c(1);
    TVectorCalendario d(1);
    d[2] = c[1] = TCalendario(28,2,2000,"ey");
    d[1] = c[2] = TCalendario(29,2,2000,"hola");

    cout <<(a==b)<< endl;
    cout <<(a!=b)<< endl;
    cout <<(b==c)<< endl;
    cout <<(d==c)<< endl;
    cout <<"_____________"<< endl;
    }

    {
    TVectorCalendario a(2);
    TVectorCalendario b(5);
    b[1] = a[1] = TCalendario(28,2,2000,"ey");
    b[2] = a[2] = TCalendario(2,5,2000,"ey");
    cout <<(a==b)<< endl;
    a.Redimensionar(3);
    b.Redimensionar(3);
    cout <<(a==b)<< endl;
    cout <<"_____________"<< endl;

    cout <<a.ExisteCal(TCalendario(28,2,2000,"ey"))<< endl;
    cout <<a.Ocupadas()<< endl;
    a.MostrarMensajes(1,5,1900); cout << endl;
    cout <<a<< endl;
    cout <<"lista_____________"<< endl;
    }

    //=========================================

    {
    TCalendario c1(14, 1, 1966, "Fecha Correcta");
    TCalendario c2(1, 1, 1954, "Fecha Correcta");
    TCalendario c3(1, 1, 1955, "Fecha Correcta");
    TCalendario c4(1, 1, 1985, "Fecha Correcta");
    TCalendario c5(2, 1, 1971, "Fecha Correcta");
    TCalendario c6(1, 1, 2955, "Fecha Correcta");
    TCalendario c7(1, 1, 2955, "Fecha Correcta");

    TListaCalendario a;
    a.Insertar(c1);
    a.Insertar(c1);
    a.Insertar(c2);
    a.Insertar(c3);
    a.Insertar(c4);
    a.Insertar(c5);
    a.Insertar(c6);
    a.Insertar(c7);
    a.Insertar(c2);
    a.Insertar(c7);
    a.Insertar(c5);
    cout <<a<< endl;

    a.Borrar(c5);
    cout <<a<< endl;
    a.Borrar(a.Ultima());
    cout <<a<< endl;
    a.Borrar(1,1,1967);
    cout <<a<< endl;
    cout <<"_____________"<< endl;

    cout <<a.Longitud()<< endl;
    cout <<a.EsVacia()<< endl;
    cout <<a.Buscar(c3)<< endl;
    cout <<a.Buscar(c4)<< endl;
    cout <<a.Obtener(a.Primera())<< endl;
    cout <<a.Obtener(a.Ultima())<< endl;
    cout <<a.ExtraerRango(-2,2)<< endl;
    cout <<"_____________"<< endl;

    TListaCalendario b;
    b.Insertar(c1);
    b.Insertar(c2);
    cout <<b<< endl;
    b = a;
    cout <<b<< endl;
    b.Insertar(c3);
    b.Insertar(c4);
    b.Insertar(c5);
    b.Insertar(c6);
    cout <<a<< endl;
    cout <<b<< endl;

    cout <<a+b<< endl;
    cout <<a-b<< endl;
    cout <<"_____________"<< endl;

    cout <<a<< endl;
    cout <<b<< endl;
    cout <<a.SumarSubl(1,3,b,4,10)<< endl;
    cout <<"_____________"<< endl;

    TListaCalendario c = a;
    TListaCalendario c_(a);
    TListaCalendario d;
    d.Insertar(c1);
    cout <<(b==a)<< endl;
    cout <<(c==a)<< endl;
    cout <<(d==a)<< endl;
    cout <<(b==d)<< endl;
    cout <<(c==c_)<< endl;
    }

    //=========================================

    {
    TCalendario c1(14, 1, 1966, "Fecha Correcta");
    TCalendario c2(1, 1, 1954, "Fecha Correcta");
    TCalendario c3(1, 1, 1955, "Fecha Correcta");
    TCalendario c4(1, 1, 1985, "Fecha Correcta");
    TCalendario c5(2, 1, 1971, "Fecha Correcta");
    TCalendario c6(1, 1, 2955, "Fecha Correcta");
    TCalendario c7(1, 1, 2955, "Fecha Correcta");

    TABBCalendario a;
    a.Insertar(c1);
    a.Insertar(c1);
    a.Insertar(c2);
    a.Insertar(c3);
    a.Insertar(c4);
    a.Insertar(c5);
    a.Insertar(c6);
    a.Insertar(c7);
    a.Insertar(c2);
    a.Insertar(c7);
    a.Insertar(c5);
    cout <<a<< endl;

    a.Borrar(c3);
    cout <<a<< endl;
    a.Borrar(c4);
    cout <<a<< endl;
    cout <<"_____________"<< endl;

    cout <<a.Altura()<< endl;
    cout <<a.Nodos()<< endl;
    cout <<a.NodosHoja()<< endl;
    cout <<a.Raiz()<< endl;
    cout <<a.EsVacio()<< endl;
    cout <<a.Buscar(c3)<< endl;
    cout <<a.Buscar(c5)<< endl;
    cout <<a.Preorden()<< endl;
    cout <<a.Inorden()<< endl;
    cout <<a.Postorden()<< endl;
    cout <<a.Niveles()<< endl;
    cout <<"_____________"<< endl;

    TABBCalendario b;
    b.Insertar(c1);
    b.Insertar(c2);
    cout <<b<< endl;
    b = a;
    cout <<b<< endl;
    b.Insertar(c3);
    b.Insertar(c4);
    b.Insertar(c5);
    b.Insertar(c6);
    cout <<a<< endl;
    cout <<b<< endl;

    cout <<a+b<< endl;
    cout <<a-b<< endl;
    cout <<"_____________"<< endl;

    TABBCalendario c = a;
    TABBCalendario c_(a);
    TABBCalendario d;
    d.Insertar(c1);
    cout <<(b==a)<< endl;
    cout <<(c==a)<< endl;
    cout <<(d==a)<< endl;
    cout <<(b==d)<< endl;
    cout <<(c==c_)<< endl;
    }

    //=========================================

    {
    TCalendario c1(14, 1, 1966, "Fecha Correcta");
    TCalendario c2(1, 1, 1954, "Fecha Correcta");
    TCalendario c3(1, 1, 1955, "Fecha Correcta");
    TCalendario c4(1, 1, 1985, "Fecha Correcta");
    TCalendario c5(2, 1, 1971, "Fecha Correcta");
    TCalendario c6(1, 1, 2955, "Fecha Correcta");
    TCalendario c7(1, 1, 2955, "Fecha Correcta");

    TAVLCalendario a;
    a.Insertar(c1);
    a.Insertar(c1);
    a.Insertar(c2);
    a.Insertar(c3);
    a.Insertar(c4);
    a.Insertar(c5);
    a.Insertar(c6);
    a.Insertar(c7);
    a.Insertar(c2);
    a.Insertar(c7);
    a.Insertar(c5);
    cout <<a<< endl;

    a.Borrar(c3);
    cout <<a<< endl;
    a.Borrar(c4);
    cout <<a<< endl;
    cout <<"_____________"<< endl;

    cout <<a.Altura()<< endl;
    cout <<a.Nodos()<< endl;
    cout <<a.NodosHoja()<< endl;
    cout <<a.Raiz()<< endl;
    cout <<a.EsVacio()<< endl;
    cout <<a.Buscar(c3)<< endl;
    cout <<a.Buscar(c5)<< endl;
    cout <<a.Preorden()<< endl;
    cout <<a.Inorden()<< endl;
    cout <<a.Postorden()<< endl;
    cout <<a.Niveles()<< endl;
    cout <<"_____________"<< endl;

    TAVLCalendario b;
    b.Insertar(c1);
    b.Insertar(c2);
    cout <<b<< endl;
    b = a;
    cout <<b<< endl;
    b.Insertar(c3);
    b.Insertar(c4);
    b.Insertar(c5);
    b.Insertar(c6);
    cout <<a<< endl;
    cout <<b<< endl;

    cout <<a+b<< endl;
    cout <<a-b<< endl;
    cout <<"_____________"<< endl;

    TAVLCalendario c = a;
    TAVLCalendario c_(a);
    TAVLCalendario d;
    d.Insertar(c1);
    cout <<(b==a)<< endl;
    cout <<(b!=a)<< endl;
    cout <<(c==a)<< endl;
    cout <<(c!=a)<< endl;
    cout <<(d==a)<< endl;
    cout <<(b==d)<< endl;
    cout <<(c==c_)<< endl;
    }

    //=========================================

    {
    TABBCalendario A;
    TListaCalendario L;
    TVectorCalendario V;
    V = A.ABBCamino(L);
    cout << V << endl;

    TCalendario c20(20, 1, 1980, "Fecha Correcta");
    TCalendario c10(10, 1, 1980, "Fecha Correcta");
    TCalendario c5(5, 1, 1980, "Fecha Correcta");
    TCalendario c3(3, 1, 1980, "Fecha Correcta");
    TCalendario c15(15, 1, 1980, "Fecha Correcta");
    TCalendario c30(30, 1, 1980, "Fecha Correcta");
    TCalendario c22(22, 1, 1980, "Fecha Correcta");
    TCalendario c25(25, 1, 1980, "Fecha Correcta");
    TCalendario c24(24, 1, 1980, "Fecha Correcta");
    TCalendario c26(26, 1, 1980, "Fecha Correcta");
    TCalendario c21(21, 1, 1980, "Fecha Correcta");
    TCalendario c31(31, 1, 1980, "Fecha Correcta");

    TListaCalendario lista;
    lista.Insertar(c21);
    lista.Insertar(c22);
    lista.Insertar(c31);

    TABBCalendario abb;
    abb.Insertar(c20);
    abb.Insertar(c10);
    abb.Insertar(c5);
    abb.Insertar(c3);
    abb.Insertar(c15);
    abb.Insertar(c30);
    abb.Insertar(c22);
    abb.Insertar(c25);
    abb.Insertar(c24);
    abb.Insertar(c26);

    cout <<abb.ABBCamino(lista)<< endl;
    cout <<abb<< endl;
    }
}