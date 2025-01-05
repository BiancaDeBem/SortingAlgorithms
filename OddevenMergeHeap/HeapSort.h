#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

/*
O Heap Sort e um algoritmo de ordenacao eficiente que funciona em duas fases principais: construcao do heap e ordenacao. Primeiro,
o array e transformado em um heap maximo, onde cada no pai e maior ou igual aos seus filhos. Em seguida, o maior elemento (na raiz do heap)
e repetidamente trocado com o ultimo elemento do heap e removido da estrutura, enquanto o heap e ajustado para manter a propriedade de heap maximo.
Esse processo continua ate que todos os elementos estejam ordenados. O Heap Sort possui complexidade de tempo 0(nlog n) e usa espaco adicional 0(1) ,
tornando-o eficiente e "in-place".
*/

#include "ListaEstatica.h"
#include <iostream>

using namespace std;

template<typename T, int tmax>
void heapify(ListaEstaticaGenerica<T,tmax>& lista, int n, int i,int &comparacoes){
    int maior = i;                                                                  //inicializa o maior nodo como raiz
    int esq = 2*i+1;                                                                //indice do filho esquedo
    int dir = 2*i+2;                                                                //indice do filho direito

    if(esq < n && lista.elementos[esq] > lista.elementos[maior]){                   //Se o o filho esquerdo for maior que a raiz
        maior = esq;                                                                //Atribui o valor da esquerda como maior
        comparacoes++;
    }

    if(dir < n && lista.elementos[dir] > lista.elementos[maior]){                   //Se o filho direito e maior que o maior ate agora
        maior = dir;                                                                //Atribui o valor da direita como maior
        comparacoes++;
    }

    if(maior != i){                                                                 //Se o maior nao for raiz
        swap(lista.elementos[i], lista.elementos[maior]);                           //Troca de lugar o maior elemento e o elemento da posicao i
        heapify(lista,n,maior,comparacoes);                                         //Ajusta recursivamente o heap
        cout << endl << "Etapa " << comparacoes << " de organizacao: " << endl;     //Mostra a lista a etapa x de organizacao
        mostra(lista);
    }
    cout << endl;

}

template<typename T, int tmax>
void heapSort(ListaEstaticaGenerica<T,tmax>& lista, int n, int &iteracoes){
    for(int i = n/2; i >= 0; i--)                                                   //Monta o heap(rearranja a lista)
        heapify(lista,n,i,iteracoes);                                               //Chama o heapify

    for(int i = n-1; i > 0; i--){                                                   //Varre o vetor do tamanho maximo da lista ate zero
        swap(lista.elementos[0], lista.elementos[i]);                               //Move a raiz atual para o final do array
        heapify(lista,i,0,iteracoes);                                               //Chama o heapify no heap menor(reduzido)
        cout << endl << "Etapa " << iteracoes << " de organizacao: " << endl;       //Mostra o vetor ordenado
        mostra(lista);
    }
}

#endif // HEAPSORT_H_INCLUDED
