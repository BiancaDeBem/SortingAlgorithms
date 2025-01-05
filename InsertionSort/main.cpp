#include <iostream>
#include <string>
#include "BB-InsertionSort.h"
#include "ListaEstatica.h"
#include "Interface.h"
#include "Sequencial-InsertionSort.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "portuguese");
    string palavras[50] = { "uva","laranja","pera","maracuj�","banana","lim�o","kiwi","abacate","amora","framboesa","caqui","acerola",
    "jabuticaba","tangerina","mel�o","ameixa","melancia","pitaia","caju","cacau","p�ssego"};

    ListaEstaticaGenerica<string, 50> lista;

    int opcao, iteracoes1=0, iteracoes2=0;
    bool passou1=false, passou2=false;
    cria(lista);


    while(true){
        preencheLista(lista, palavras, 21);
        opcao = LerMenu();

        system("cls");

        switch(opcao){
            case 1:
                cout << "Lista sem ordena��o: " << endl ;
                mostra(lista);
                cout << endl;

                sequencialInsertionSort(lista,iteracoes1);

                printBarra();
                cout << endl <<  "Lista ordenada com insertion sort com busca sequencial: " << endl;
                mostra(lista);
                cout << endl <<endl << "Quantidade de itera��es: " << iteracoes1 << endl;
                passou1 = true;
                break;

            case 2:
                cout << "Lista sem ordena��o: " << endl;
                mostra(lista);
                cout << endl;

                bbInsertionSort(lista, iteracoes2);

                printBarra();
                cout << endl << endl << "Lista ordenada com insertion sort com busca bin�ria: " << endl;
                mostra(lista);
                cout << endl <<endl << "Quantidade de itera��es: " << iteracoes2 << endl;
                passou2 = true;
                break;


            default:
                cout << "N�mero fora do intervalo!" << endl;
        }

        if(passou1 && passou2){
            if(iteracoes1 > iteracoes2) cout << endl << "O m�todo por ordena��o bin�ria � mais eficiente!" << endl << endl;
            else cout << endl << "O m�todo por ordena��o sequencial � mais eficiente!" << endl << endl;
        }

        destroi(lista);
        iteracoes1 = 0;
        iteracoes2 = 0;
        if (!DesejaContinuar()) break;
        system("cls");

    }
    return 0;
}
