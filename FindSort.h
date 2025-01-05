#ifndef FINDSORT_H_INCLUDED
#define FINDSORT_H_INCLUDED

#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include "ListaEstática.h"

///FindSort
template<typename T, int tmax>
// Funcao de particao que rearranja os elementos em torno do pivo
int Particao(ListaEstaticaGenerica<T,tmax> &lista , int menor, int maior, int& comparacoes) {
    int pivo = lista.elementos[maior];                                      // Escolhe o ultimo elemento como pivo
    int i = menor - 1;                                                      // Indice do menor elemento

    for (int j = menor; j < maior; j++) {
        if (lista.elementos[j] <= pivo) {                                   // Se o elemento atual for menor ou igual ao pivo
            i++;
            swap(lista.elementos[i], lista.elementos[j]);
            comparacoes++;
        }
    }
    swap(lista.elementos[i+1], lista.elementos[maior]);

    return i + 1;
}

// Funcao principal do FindSort
template<typename T, int tmax>
int findSort(ListaEstaticaGenerica<T,tmax> &lista, int menor, int maior, int k,int& comparacoes) {
    if (menor <= maior) {

        int pi = Particao(lista, menor, maior, comparacoes);                          // Encontra o indice de particao

        if (pi == k) return lista.elementos[pi];                                      // Se o indice de particao e igual a k, encontramos o k-esimo menor elemento
        else if (pi > k) return findSort(lista, menor, pi - 1, k,comparacoes);        // Se o indice de particao e maior que k, procura na sublista esquerda
        else return findSort(lista, pi + 1, maior, k,comparacoes);                    // Se o indice de particao e menor que k, procura na sublista direita

    }
    return -1;                                                                        // Esta linha e para evitar warning
}

#endif // FINDSORT_H_INCLUDED
