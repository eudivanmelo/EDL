#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main()
{
    /*
    3. Lista Duplamente Encadeada - Inserção Ordenada
        Implemente uma lista duplamente encadeada onde os elementos são inseridos
        de forma ordenada. O usuário deve inserir um número e o programa deve
        posicioná-lo no local correto para manter a ordem crescente.
    */
    DoublyLinkedList<int> Dl;

    Dl.append(10);
    Dl.append(12);
    Dl.append(13);
    Dl.append(11);
    Dl.append(8);
    Dl.append(10);
    Dl.append(110);
    Dl.append(15);
    Dl.append(1);

    Dl.print();


    /*
    4. Lista Duplamente Encadeada - Remoção
        Dada uma lista duplamente encadeada, implemente uma função para remover
        um nó específico e ajustar os ponteiros dos nós vizinhos corretamente.
    */
    Dl.removeElement(11);

    Dl.print();

    return 0;
}
