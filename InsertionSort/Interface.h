#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>
#include <string>

int LerMenu(){
    setlocale(LC_ALL,"portuguese");
    int opcao;

    cout << "1 - Insert Sort Sequencial" << endl
         << "2 - Insert Sort Por Busca Binária" << endl;
    cout << "Escolha uma opção: ";
    cin >> opcao;

    return opcao;
}

bool DesejaContinuar(){
    char para;

    cout << "Deseja continuar? s/n: ";
    cin >> para;
    if(para == 's') return true;
    else return false;
}

template<typename T>
void mostraListaComum(T lista[], int n){
    for(int i=0; i<n; i++)
        cout << "[" << lista[i] << "] ";
}

void printBarra(){
    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
}
#endif // INTERFACE_H_INCLUDED
