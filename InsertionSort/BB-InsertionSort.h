#ifndef BBINSERTIONSORT_H_INCLUDED
#define BBINSERTIONSORT_H_INCLUDED

#include <iostream>
#include <string>
#include "ListaEstatica.h"

using namespace std;

template<typename T, int tmax>
void bbInsertionSort(ListaEstaticaGenerica<T, tmax>& lista,int &iteracoes){
    setlocale(LC_ALL,"portuguese");

    int j=0,posicao=0;
    T chave;

    for (int i = 1; i < lista.cardinalidade; i++) {
        chave = lista.elementos[i];                             // Elemento atual a ser inserido na parte ordenada
        j = i - 1;

        posicao = buscaBinaria(lista, chave, iteracoes, i);

        while (j >= posicao) {                                  // Move os elementos da parte ordenada que sao maiores que a chave para a direita
            lista.elementos[j + 1] = lista.elementos[j];
            j--;
        }


        lista.elementos[j + 1] = chave;
    }
}
template<typename T, int tmax>
int buscaBinaria(ListaEstaticaGenerica<T,tmax> lista, T chave, int& iteracoes, int tam) {
    setlocale(LC_ALL, "portuguese");
    int esq = 0;
    int dir = tam - 1;

    while (esq <= dir) {
        int meio = esq + (dir - esq) / 2;
        iteracoes++;

        if (lista.elementos[meio] == chave)return meio;                        // Verifica se a chave esta no meio

        if (lista.elementos[meio] < chave)esq = meio + 1;                        // Se a chave e maior, ignora a metade esquerda
        else dir = meio - 1;                                                   // Se a chave e menor, ignora a metade direita


    }

    return esq;                                                     // Se a chave nao esta dentro do vetor ordenado
}


#endif // BBINSERTIONSORT_H_INCLUDED
