#ifndef LISTAESTATICA_H_INCLUDED
#define LISTAESTATICA_H_INCLUDED

#include <iostream>

using namespace std;

template<typename T, int MAX>                                                   //Esse max define o tamanho do vetor de forma flexivel(O user pode escolher o tamanho)
struct ListaEstaticaGenerica{

    int cardinalidade;
    T elementos [MAX];
};

template<typename T, int MAX>
void cria(ListaEstaticaGenerica<T, MAX> &lista){                                //Cria a lista
    lista.cardinalidade = 0;                                                    //Define a cardinalidade em zero
}

template<typename T, int MAX>
void destroi(ListaEstaticaGenerica<T,MAX>& lista){
    lista.cardinalidade = 0;
}

template<typename T, int MAX>
bool VerificaListaVazia(ListaEstaticaGenerica<T, MAX> lista){                   //Verifica se a lista está vazia
    return lista.cardinalidade == 0;                                            //Retorna true se a cardinalidade é igual a 0
}

template<typename T, int MAX>
bool VerificaListaCheia (ListaEstaticaGenerica<T, MAX> lista){                  //Verifica se a lista está cheia
    return lista.cardinalidade >= MAX;                                          //Retorna true se o tamanho máximo for maior ou igual a cardinalidade
}

template<typename T, int MAX>
int TamanhoDaLista (ListaEstaticaGenerica<T, MAX> lista){                       //Retorna o tamanho da lista
    return lista.cardinalidade;                                                 //retorna a cardinalidade
}

template<typename T, int MAX>
bool existeElemento (ListaEstaticaGenerica<T, MAX> lista, T elemento){          //Verifica a existência de um elemento
    for (int i = 0; i < lista.cardinalidade; i++)                               //Procura o elemento no vetor
        if (lista.elementos[i] == elemento)                                     //Se o elemento da lista for igual ao da busca retorna true
            return true;
    return false;                                                               //Senão retorna false
}

template<typename T, int MAX>
bool VerificaPosicaoValida (ListaEstaticaGenerica<T, MAX> lista, T posicao){    //Verifica de uma posição é valida
    return ((posicao >= 1) && (posicao <= lista.cardinalidade));                //Retorna true se a posição informada for maior que 1 e menor ou igual a cardinalidade
}

template<typename T, int MAX>
int RecuperaElemento (ListaEstaticaGenerica<T, MAX> lista, T posicao){          //Recupera um elemento
    return lista.elementos[posicao - 1];                                        //Devolve o elemento na posição x - 1 (posição fisica, e não lógica)
}

template<typename T, int MAX>
int posicao (ListaEstaticaGenerica<T, MAX> lista, T elemento){                  //Retorna a posição de um elemento
    int i = 0;
    while (lista.elementos[i] != elemento)                                      //Enquanto a posição do vetor for diferente do valor para busca soma +1 no i
        i++;
    return i + 1;                                                               //Se for igual retorna i+1 (posição lógica)
}

template<typename T, int MAX>
void insere (ListaEstaticaGenerica<T, MAX> &lista, T elemento, int posicao){    //Insere um elemento na lista independentemente da posição
    if(VerificaListaCheia(lista)) cout << "A lista está cheia!" << endl;        //Verifica se a lista está cheia
    else{
        if(lista.cardinalidade != 0){                                           //Se a cardinalidade da lista for diferente de zero, todos os elementos são movidos até
         for (int i = lista.cardinalidade; i >= posicao; i--)                   // o local da inserção do novo
            lista.elementos[i] = lista.elementos[i - 1];
        }
     lista.elementos[posicao] = elemento;                                       //Coloca o novo elemento em sua posição
     lista.cardinalidade++;                                                     //Incrementa a cardinalidade
    }
}

template<typename T, int MAX>
void retira (ListaEstaticaGenerica<T, MAX> &lista, T posicao){                  //Retira um elemento da lista independetemente da posição
    if(VerificaListaVazia(lista))
        cout << "A lista não tem elementos para retirada" << endl;
    else{
        for (int i = posicao; i < lista.cardinalidade; i++)                     //For que vai da posição informada até o fim da lista
            lista.elementos[i - 1] = lista.elementos[i];                        //Sobrepõe o elemente a ser retirado puxando todos os elementos da lista uma posição para trás


        lista.cardinalidade--;                                                  //Decrementa a cardinalidade
    }
}

template<typename T, int MAX>
void mostra (ListaEstaticaGenerica<T,MAX> lista){                               //Exibe a lista
    for (int i = 0; i < lista.cardinalidade; i++)                               //Percorre a lista toda
        cout << "["<<lista.elementos[i] << "] ";                                //Elemento a elemento a lista
}

template <typename T, int MAX>
void preencheLista(ListaEstaticaGenerica<T,MAX>& lista, T valores[], int n){    //Preenche a lista estática genérica a partir de uma outra lista comum preenchida
    for(int i=0; i<n; i++){                                                     //Percorre a lista comum toda
        insere(lista,valores[i],i);                                             //Coloca os valores da lista comum na lista estática genérica
    }
}

#endif // LISTAESTATICA_H_INCLUDED
