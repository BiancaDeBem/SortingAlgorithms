#ifndef SEQUENCIALINSERTIONSORT_H_INCLUDED
#define SEQUENCIALINSERTIONSORT_H_INCLUDED

#include <iostream>
#include <string>
#include "ListaEstatica.h"

using namespace std;

template<typename T, int MAX>
void sequencialInsertionSort(ListaEstaticaGenerica<T, MAX>& lista,int &iteracoes) {
    setlocale(LC_ALL,"portuguese");
    int j=0;
    T chave;
    for (int i = 1; i < lista.cardinalidade; i++) {
        chave = lista.elementos[i];                         // Elemento atual a ser inserido na parte ordenada
        j = i - 1;
                                                            // Move os elementos da parte ordenada que são maiores que a chave para a direita
        while (j >= 0 && lista.elementos[j] > chave) {
            lista.elementos[j + 1] = lista.elementos[j];
            j--;
            iteracoes++;
        }

        lista.elementos[j + 1] = chave;
    }
}



#endif // SEQUENCIALINSERTIONSORT_H_INCLUDED
