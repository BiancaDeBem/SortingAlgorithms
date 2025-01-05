#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>

using namespace std;

int LerMenu(){
    setlocale(LC_ALL,"portuguese");
    int opcao;

    cout << "1 - Odd Even sort" << endl;
    cout << "2 - Merge sort" << endl;
    cout << "3 - Heap sort" << endl;
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

#endif // INTERFACE_H_INCLUDED
