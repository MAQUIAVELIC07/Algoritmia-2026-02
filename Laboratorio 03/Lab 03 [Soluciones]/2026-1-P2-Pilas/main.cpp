#include <iostream>

#include "BibliotecaPila/funcionesPila.h"
#include "BibliotecaPila/Pila.h"
//SOLUCION CON 2 PILAS
bool verificarCon2Pilas(Pila &pila,int arrLlegada[4],int arrCliente[4]) {
    ElementoPila elemento;
    Pila pilaAux;
    construir(pilaAux);
    int n = 0;
    for (int i = 0; i < 4; i++) {
        elemento.numero = arrLlegada[i];
        apilar(pila,elemento);
        while (!esPilaVacia(pila)) {
            if (cima(pila).numero == arrCliente[n]) {
                ElementoPila elementoAux;
                elementoAux = desapilar(pila);

                apilar(pilaAux,elementoAux);
                n++;
            }else {
                break;
            }
        }
    }
    int lon = longitud(pilaAux);
    if (lon == 4) {
        return true;
    }
    return false;
}
//1  2  3  4
//1  3  4  2

//SOLUCION CON 1 PILA
bool verificarCon1Pila (Pila &pila,int arrLlegada[4],int arrCliente[4]) {
    ElementoPila elemento;
    int n = 0;
    for (int i = 0; i < 4; i++) {
        elemento.numero = arrLlegada[i];
        apilar(pila,elemento);
        while (!esPilaVacia(pila)) {
            if (cima(pila).numero == arrCliente[n]) {
                ElementoPila elementoAux;
                elementoAux = desapilar(pila);
                n++;
            }else {
                break;
            }
        }
    }
    if (n == 4) {
        return true;
    }
    return false;
}



using namespace std;

//SOLUCION COMPARANDO ARREGLOS
void verificarSiEsPosible(int ordenInicial[],int ordenFinal[],Pila &pilaAux,const int n){
    ElementoPila elemento_pila;
    int i=0,j=0;
    while (i<n){
        if (ordenInicial[i]==ordenFinal[j]){
            i++;
            j++;
        }else{
            elemento_pila.numero=ordenInicial[i];
            apilar(pilaAux,elemento_pila);
            i++;
        }
    }
    bool esIgual=false;
    for (j;j<n;j++){
        elemento_pila=desapilar(pilaAux);
        if (elemento_pila.numero==ordenFinal[j]){
            esIgual=true;
        }else{
            esIgual=false;
            break;
        }
    }
    if (esIgual==true){
        cout<<"Si cumple"<<endl;
    }else{
        cout<<"No cumple tu webd"<<endl;
    }
}
int main() {
    // int n= 4;
    Pila pila;
    construir(pila);
    int n = 4;
    int arrLlegada[4] = {1, 2, 3, 4};
    int arrCliente[4] = {1, 3, 4, 2};


    // verificarSiEsPosible(arrLlegada,arrCliente,pila,n);

    if (verificarCon1Pila(pila,arrLlegada,arrCliente)) {
        cout<<"Se puede cumplir con lo solicitado"<<endl;
    }else {
        cout<<"No se puede cumplir con lo solicitado"<<endl;
    }

    return 0;
}