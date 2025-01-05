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
    string palavras[50] = { "uva","laranja","pera","maracujá","banana","limão","kiwi","abacate","amora","framboesa","caqui","acerola",
    "jabuticaba","tangerina","melão","ameixa","melancia","pitaia","caju","cacau","pêssego"};

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
                cout << "Lista sem ordenação: " << endl ;
                mostra(lista);
                cout << endl;

                sequencialInsertionSort(lista,iteracoes1);

                printBarra();
                cout << endl <<  "Lista ordenada com insertion sort com busca sequencial: " << endl;
                mostra(lista);
                cout << endl <<endl << "Quantidade de iterações: " << iteracoes1 << endl;
                passou1 = true;
                break;

            case 2:
                cout << "Lista sem ordenação: " << endl;
                mostra(lista);
                cout << endl;

                bbInsertionSort(lista, iteracoes2);

                printBarra();
                cout << endl << endl << "Lista ordenada com insertion sort com busca binária: " << endl;
                mostra(lista);
                cout << endl <<endl << "Quantidade de iterações: " << iteracoes2 << endl;
                passou2 = true;
                break;


            default:
                cout << "Número fora do intervalo!" << endl;
        }

        if(passou1 && passou2){
            if(iteracoes1 > iteracoes2) cout << endl << "O método por ordenação binária é mais eficiente!" << endl << endl;
            else cout << endl << "O método por ordenação sequencial é mais eficiente!" << endl << endl;
        }

        destroi(lista);
        iteracoes1 = 0;
        iteracoes2 = 0;
        if (!DesejaContinuar()) break;
        system("cls");

    }
    return 0;
}
