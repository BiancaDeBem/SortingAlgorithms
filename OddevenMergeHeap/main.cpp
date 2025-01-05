#include "ListaEstatica.h"
#include "OddEven.h"
#include "MergeSort.h"
#include "HeapSort.h"
#include "Interface.h"

#include <iostream>

using namespace std;

int main()
{
    int valores[20] = {6, 30, 18, 15, 22, 7, 3, 19, 25, 12, 18, 9, 21, 22};                             //Declarando um vetor comum preenchido com os valores a serem ordenados
    ListaEstaticaGenerica<int, 50> lista;                                                               //Declarando a lista estática
    int opcao, iteracoes;
    cria(lista);                                                                                        //Criando a lista estática


    while(true){
        preencheLista(lista, valores,14);                                                               //Preenche a lista a estática com os valores do vetor comum
        opcao = LerMenu();                                                                              //Lê o comando do usuário
        system("cls");                                                                                  //Limpa a tela

        switch(opcao){                                                                                  //switch-case que escolhe um case baseado na opção escolhida pelo usuário
            case 1:
                cout << "Lista sem ordenação: " << endl ;                                               //Mostra a lista antes de ser ordenada (Esse trecho se repete em todos os case)
                mostra(lista);
                cout << endl;                                                                           //Quebra de linha

                OddEvenSort(lista, TamanhoDaLista(lista), iteracoes);                                   //Chamada da função de ordenação Odd Even Sort

                cout << "Lista ordenada com odd even sort: " << endl;                                   //Mostra a lista após ser ordenada (Esse trecho se repete em todos os case)
                mostra(lista);
                break;

            case 2:
                cout << "Lista sem ordenação: " << endl;
                mostra(lista);

                MergeSort(lista,0,TamanhoDaLista(lista),iteracoes);                                     //Chamada da função de ordenação Merge Sort

                cout << endl << endl << "Lista ordenada com merge sort: " << endl;
                mostra(lista);
                cout << endl;
                break;
            case 3:
                cout << "Lista sem ordenação: " << endl;
                mostra(lista);

                heapSort(lista, TamanhoDaLista(lista),iteracoes);                                       //Chamada da função de ordenação Heap Sort

                cout << endl << "Lista ordenada com heap sort: " << endl;
                mostra(lista);
                cout <<  endl;
                break;

            default:
                cout << "Número fora do intervalo!" << endl;                                            //É exibido caso um número não exitente seja digitado
        }
        cout << endl << "Quantidade de iterações: " << iteracoes << endl;                               //Exibe a quantidade de comparações independentemente do tipo de ordenação escolhido
        iteracoes = 0;                                                                                  //Sete o contador de comparações em 0
        if (!DesejaContinuar()) break;                                                                  //Pergunta se o usuário dejesa ver o vetor ordenado com outro método
        system("cls");                                                                                  //Limpa a tela

    }
    return 0;
}
