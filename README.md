# Algoritmos de Ordenação
A seguir contém uma breve explicação dos algoritmos presentes nos arquivos a seguir.

-> todas as imagens de exemplo abaixo foram retiradas do site geeks for geeks https://www.geeksforgeeks.org/

## Odd Even
Esse metodo organiza uma lista percorrendo ela em 2 etapas.
Uma vez por indices impares e outra por indices pares para organizar o vetor todo.
Enquanto o vetor nao esta organizado ele continua comparando o vetor em 2 etapas.
Esse metodo tem base no bubble sort. (outro nome para o metodo: brick sort)

## Merge Sort
Esse metodo de organizacao de forma resumida divide o vetor em 2 metades, organiza cada uma e depois junta essas 2 metades
e repete esse processo ate que o vetor esteja ordenado.

## Heap Sort
O Heap Sort e um algoritmo de ordenacao eficiente que funciona em duas fases principais: construcao do heap e ordenacao. Primeiro,
o array e transformado em um heap maximo, onde cada no pai e maior ou igual aos seus filhos. Em seguida, o maior elemento (na raiz do heap)
e repetidamente trocado com o ultimo elemento do heap e removido da estrutura, enquanto o heap e ajustado para manter a propriedade de heap maximo.
Esse processo continua ate que todos os elementos estejam ordenados. O Heap Sort possui complexidade de tempo 0(nlog n) e usa espaco adicional 0(1) ,
tornando-o eficiente e "in-place".

## Quick Sort
Consiste em 4 etapaas: 

Escolha um Pivô: Selecione um elemento do array como o pivô. A escolha do pivô pode variar (por exemplo, primeiro elemento, último elemento, elemento aleatório ou a mediana).

Particione o Array: Reorganize o array em torno do pivô. Após a partição, todos os elementos menores que o pivô ficarão à esquerda, e todos os elementos maiores que o pivô ficarão à direita. O pivô então estará em sua posição correta, e obtemos o índice do pivô.

Chamada Recursiva: Aplique recursivamente o mesmo processo aos dois sub-arrays particionados (esquerda e direita do pivô).

Caso Base: A recursão para quando houver apenas um elemento no sub-array, pois um único elemento já está ordenado.
![image](https://github.com/user-attachments/assets/6d5b922a-66b2-45f3-9102-cba2353bee72)


## Insertion Sort
Escolha um Pivô: Selecione um elemento do array como o pivô. A escolha do pivô pode variar (por exemplo, primeiro elemento, último elemento, elemento aleatório ou a mediana).  

Particione o Array: Reorganize o array em torno do pivô. Após a partição, todos os elementos menores que o pivô ficarão à esquerda, e todos os elementos maiores que o pivô ficarão à direita. O pivô então estará em sua posição correta, e obtemos o índice do pivô.  

Chamada Recursiva: Aplique recursivamente o mesmo processo aos dois sub-arrays particionados (esquerda e direita do pivô).  

Caso Base: A recursão para quando houver apenas um elemento no sub-array, pois um único elemento já está ordenado.  
![image](https://github.com/user-attachments/assets/cc9c77de-c3f4-4ad1-9a89-5c188cad3bcc)


## Find Sort
Esse métode encontra um elemento, utilizando o método Quick Sort o método de percorrer a lista


