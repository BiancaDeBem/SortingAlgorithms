#include <iostream>
#include "ListaEstática.h"
#include "FindSort.h"
#include "Interface.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    int comparacoes=0,k=0;
    bool continua = false;
    int valores[20] = {50,4,21,33,11,8,7,55,19,27};

    ListaEstaticaGenerica<int, 20> lista;

    do{
        cria(lista);
        preencheLista(lista, valores,10);
        do{
            cout << "Informe o k menor elemento desejado: ";
            cin >> k;
            if(k < 0 && k >= 10) cout << "O valor informado precisa estar entre 1 e 10" << endl << endl;
        }while(k < 0 && k >= 10);

        cout << endl << "Lista sem ordenação: " << endl ;
        mostra(lista);
        cout << endl << endl;

        cout << "Menor elemento da posição " << k << ": " << findSort(lista,0,TamanhoDaLista(lista)-1,k-1, comparacoes) << endl << endl;

        cout << "Quantidade de comparações: " << comparacoes << endl << endl;

        cout << endl << "Lista após a busca: " << endl ;
        mostra(lista);
        cout << endl << endl;

        comparacoes = 0;

        continua = DesejaContinuar();
        destroi(lista);
        system("cls");
    }while(continua);

    return 0;
}
