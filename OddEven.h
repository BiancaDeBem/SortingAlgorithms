#ifndef ODDEVEN_H_INCLUDED
#define ODDEVEN_H_INCLUDED

/*Esse metodo organiza uma lista percorrendo ela em 2 etapas.
Uma vez por indices impares e outra por indices pares para organizar o vetor todo.
Enquanto o vetor nao esta organizado ele continua comparando o vetor em 2 etapas.
Esse metodo tem base no bubble sort. (outro nome para o metodo: brick sort) */

#include "ListaEstatica.h"
#include <iostream>

using namespace std;

template<typename T, int tmax>
void OddEvenSort(ListaEstaticaGenerica<T,tmax>& lista, int n, int &comparacoes){
    bool estaOrganizado = false;                                                            //Validacao se a lista esta finalmente ordenada
    int i=0;

    while(!estaOrganizado){                                                                 //Enquanto a lista nao esta ordenada
        estaOrganizado = true;                                                              //Seta esta ordenado em true

        //Numeros impares
        cout << endl << "Impares: " << endl;
        for(i=1; i<=n-2; i+=2){                                                             //Percorre a lista nas posicoes impares
            if(lista.elementos[i] > lista.elementos[i+1]){                                  //Compara o indice atual com o da posicao seguinte e se for maior troca de posicao
                swap(lista.elementos[i],lista.elementos[i+1]);
                estaOrganizado = false;                                                     //Define estaOrganizado em false

                comparacoes++;                                                              //Acrescenta 1 as comparacoes por causa do if
                cout << "Etapa " << comparacoes << " de organização: " << endl;             //Exibe as comparacoes
                mostra(lista);
                cout << endl << endl;
            }
        }
        cout << endl << "Pares: " << endl;
        //Numeros pares
        for(i=0; i<=n-2; i+=2){                                                             //Percorre a lista nas posicoes pares
            if(lista.elementos[i] > lista.elementos[i+1]){                                  //Compara o indice atual com o da posicao seguinte e se for maior troca de posicao
                swap(lista.elementos[i],lista.elementos[i+1]);
                estaOrganizado = false;                                                     //Define estaOrganizado em false

                comparacoes++;                                                              //Acrescenta 1 as comparacoes por causa do if
                cout << "Etapa " << comparacoes << " de organiza��o: " << endl;             //Exibe as comparacoes
                mostra(lista);
                cout << endl << endl;
            }
        }
    }
}

#endif // ODDEVEN_H_INCLUDED
