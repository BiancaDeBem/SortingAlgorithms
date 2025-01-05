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
    ListaEstaticaGenerica<int, 50> lista;                                                               //Declarando a lista est�tica
    int opcao, iteracoes;
    cria(lista);                                                                                        //Criando a lista est�tica


    while(true){
        preencheLista(lista, valores,14);                                                               //Preenche a lista a est�tica com os valores do vetor comum
        opcao = LerMenu();                                                                              //L� o comando do usu�rio
        system("cls");                                                                                  //Limpa a tela

        switch(opcao){                                                                                  //switch-case que escolhe um case baseado na op��o escolhida pelo usu�rio
            case 1:
                cout << "Lista sem ordena��o: " << endl ;                                               //Mostra a lista antes de ser ordenada (Esse trecho se repete em todos os case)
                mostra(lista);
                cout << endl;                                                                           //Quebra de linha

                OddEvenSort(lista, TamanhoDaLista(lista), iteracoes);                                   //Chamada da fun��o de ordena��o Odd Even Sort

                cout << "Lista ordenada com odd even sort: " << endl;                                   //Mostra a lista ap�s ser ordenada (Esse trecho se repete em todos os case)
                mostra(lista);
                break;

            case 2:
                cout << "Lista sem ordena��o: " << endl;
                mostra(lista);

                MergeSort(lista,0,TamanhoDaLista(lista),iteracoes);                                     //Chamada da fun��o de ordena��o Merge Sort

                cout << endl << endl << "Lista ordenada com merge sort: " << endl;
                mostra(lista);
                cout << endl;
                break;
            case 3:
                cout << "Lista sem ordena��o: " << endl;
                mostra(lista);

                heapSort(lista, TamanhoDaLista(lista),iteracoes);                                       //Chamada da fun��o de ordena��o Heap Sort

                cout << endl << "Lista ordenada com heap sort: " << endl;
                mostra(lista);
                cout <<  endl;
                break;

            default:
                cout << "N�mero fora do intervalo!" << endl;                                            //� exibido caso um n�mero n�o exitente seja digitado
        }
        cout << endl << "Quantidade de itera��es: " << iteracoes << endl;                               //Exibe a quantidade de compara��es independentemente do tipo de ordena��o escolhido
        iteracoes = 0;                                                                                  //Sete o contador de compara��es em 0
        if (!DesejaContinuar()) break;                                                                  //Pergunta se o usu�rio dejesa ver o vetor ordenado com outro m�todo
        system("cls");                                                                                  //Limpa a tela

    }
    return 0;
}
