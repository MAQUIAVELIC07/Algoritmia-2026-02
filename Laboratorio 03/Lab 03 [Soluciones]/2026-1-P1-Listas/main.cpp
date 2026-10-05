#include <iostream>

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

using namespace  std;

int contarOcurrencias(const Lista &lista,const int dato) {
    int cant = 0;
    NodoLista *recorrido;
    recorrido = lista.inicio;
    while (recorrido!= nullptr) {
        if (recorrido->elemento.codigo == dato) {
            cant++;
        }
        recorrido = recorrido->siguiente;
    }
    return cant;
}

bool estaEnLista(const Lista &lista,const int dato) {
    bool veri = false;
    NodoLista *recorrido;
    recorrido = lista.inicio;
    while (recorrido!= nullptr) {
        if (recorrido->elemento.codigo == dato) {
            veri = true;
            break;
        }
        recorrido = recorrido->siguiente;
    }

    return veri;
}

void crearListaSospechosos(Lista &lista,Lista &listaSospechosos) {
    NodoLista *recorrido;
    recorrido = lista.inicio;
    ElementoLista dato;
    while (recorrido!= nullptr) {
        int cant = contarOcurrencias(lista,recorrido->elemento.codigo);
        if (not estaEnLista(listaSospechosos,recorrido->elemento.codigo) and cant>=3) {
            dato.codigo = recorrido->elemento.codigo;
            insertarAlFinal(listaSospechosos,dato);
        }
        recorrido = recorrido->siguiente;
    }
}

void eliminarUsuariosSospechosos(Lista &lista, const Lista &listaSospechosos) {
    NodoLista *anterior = nullptr;
    NodoLista *recorrido = lista.inicio;
    while (recorrido != nullptr) {
        if (estaEnLista(listaSospechosos, recorrido->elemento.codigo)) {
            NodoLista *aEliminar = recorrido;
            recorrido = recorrido->siguiente;      // avanzo ANTES de borrar
            if (anterior == nullptr)               // era el primer nodo
                lista.inicio = recorrido;
            else                                   // nodo del medio o del final
                anterior->siguiente = recorrido;
            delete aEliminar;
            lista.longitud--;
        } else {
            anterior = recorrido;                  // este nodo se queda
            recorrido = recorrido->siguiente;
        }
    }
}

int main() {


    Lista lista;
    construir(lista);
    ElementoLista elemento;
    elemento.codigo = 410;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 102;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 205;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 102;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 205;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 330;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 102;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 205;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 410;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 205;
    insertarAlFinal(lista, elemento);
    elemento.codigo = 777;
    insertarAlFinal(lista, elemento);

    imprimir(lista);
    //CONTAR OCURRENCIAS
    // int cant410 = contarOcurrencias(lista,410);
    // int cant102 = contarOcurrencias(lista,102);
    // int cant205 = contarOcurrencias(lista,205);
    // int cant777 = contarOcurrencias(lista,777);
    // int cant330 = contarOcurrencias(lista,330);
    // //VERIFICAR
    // bool estaEnList410 = estaEnLista(lista,410);
    // bool estaEnList102 = estaEnLista(lista,102);
    // bool estaEnList205 = estaEnLista(lista,205);
    // bool estaEnList777 = estaEnLista(lista,777);
    // bool estaEnList330 = estaEnLista(lista,330);
    //GENERAR LISTA DE SOSPECHOSOS
    Lista listaSospechosos;
    construir(listaSospechosos);
    crearListaSospechosos(lista,listaSospechosos);
    eliminarUsuariosSospechosos(lista,listaSospechosos);
    imprimir(listaSospechosos);
    eliminarUsuariosSospechosos(lista, listaSospechosos);
    cout << "Lista depurada: ";
    imprimir(lista);

    // destruir(lista);
    // destruir(listaSospechosos);
    return 0;
}