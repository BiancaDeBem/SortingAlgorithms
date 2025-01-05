#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

/*Esse metodo de organizacao de forma resumida divide o vetor em 2 metades, organiza cada uma e depois junta essas 2 metades
e repete esse processo ate que o vetor esteja ordenado.
*/


#include "ListaEstatica.h"
#include "Interface.h"
#include <iostream>

using namespace std;

template<typename T, int tmax>
void Merge(ListaEstaticaGenerica<T, tmax>& lista, int esq, int meio, int dir, int& comparacoes) {
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    // Vetores tempor�rios
    T esqVet[n1];                                                                       //Declara o vetor temporario da esquerda
    T dirVet[n2];                                                                       //Declara o vetor temporario da direita

    for (int i = 0; i < n1; i++) {                                                      //Preenchendo os vetores esqVet e dirVet
        esqVet[i] = lista.elementos[esq + i];
    }
    for (int j = 0; j < n2; j++) {
        dirVet[j] = lista.elementos[meio + 1 + j];
    }

    int i = 0, j = 0, k = esq;                                                          //Declara k com o valor do inicio do vetor principal e i e j com zero

    while (i < n1 && j < n2) {                                                          //Enquanto i ou j forem menores que o tamanho dos vetores temporarios
        if (esqVet[i] <= dirVet[j]) {                                                   //Se o vetor da esquerda na posicao i for menor que a do vetor da direita na posicao j
            lista.elementos[k] = esqVet[i];                                             //entao o vetor da esquerda a colocado no vetor principal na poscao k
            i++;                                                                        //I e incrementado
        } else {
            lista.elementos[k] = dirVet[j];                                             //O vetor da direita e colocado no vetor principal na posicao k
            j++;                                                                        //J e incrementado
        }
        k++;
        comparacoes++;                                                                  //Adiciona 1 a quantidade de comparacoes
    }

    while (i < n1) {                                                                    // Copia os elementos restantes de esqVet, se houver algum
        lista.elementos[k] = esqVet[i];
        i++;
        k++;

    }

    while (j < n2) {                                                                    // Copiar os elementos restantes de dirVet, se houver algum
        lista.elementos[k] = dirVet[j];
        j++;
        k++;
    }

    cout << endl << "Etapa " << comparacoes << " de organiza��o: " << endl;               //Exibe o vetor da direita e esquerda lado a lado
    mostraListaComum(dirVet,n2);
    cout << "       ";
    mostraListaComum(esqVet,n1);
    cout << endl;

    cout << endl <<"Lista Principal: " << endl;                                         //Exibe o vetor principal
    mostra(lista);
    cout << endl;
}

template<typename T, int tmax>
void MergeSort(ListaEstaticaGenerica<T, tmax>& lista, int esq, int dir, int& comparacoes) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;

        // Ordena a primeira e a segunda metade
        MergeSort(lista, esq, meio, comparacoes);
        MergeSort(lista, meio + 1, dir, comparacoes);

        // Mescla as metades ordenadas
        Merge(lista, esq, meio, dir, comparacoes);
    }
}

#endif // MERGESORT_H_INCLUDED
