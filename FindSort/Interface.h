#ifndef INTERFACE_H_INCLUDED
#define INTERFACE_H_INCLUDED

#include <iostream>

using namespace std;

bool DesejaContinuar(){
    setlocale(LC_ALL, "portuguese");
    char para;

    cout << "Deseja pesquisar outro número? s/n: ";
    cin >> para;
    if(para == 's') return true;
    else return false;
}

#endif // INTERFACE_H_INCLUDED
