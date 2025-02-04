#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
    /*
    1. Lista Encadeada Simples
        Implemente uma lista encadeada simples em C++ contendo as operações
        básicas:
        • Inserir um elemento no início.
        • Inserir um elemento no final.
        • Remover um elemento específico da lista.
        • Buscar um elemento na lista.
        • Exibir os elementos da lista.
    */

    LinkedList<int> l;

    l.insertOnEnd(10);
    l.insertOnEnd(5);
    l.insertOnEnd(2);
    l.insertOnEnd(4);
    l.insertOnEnd(3);
    l.insertOnEnd(2);
    l.insertOnEnd(2);
    l.insertOnEnd(5);

    l.insertOnBegin(22);

    l.removeElement(3);

    l.print();

    /*
    2. Lista Encadeada - Remoção de Duplicatas
        Dada uma lista encadeada simples, escreva um algoritmo que remova todos os
        elementos duplicados, garantindo que cada valor apareça apenas uma vez.
    */

    l.removeDuplicates();

    l.print();

    return 0;
}
