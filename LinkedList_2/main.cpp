#include <iostream>
#include "doublylinkedlist.h"

using namespace std;

int main()
{
    /*
    3. Lista Duplamente Encadeada - Inser��o Ordenada
        Implemente uma lista duplamente encadeada onde os elementos s�o inseridos
        de forma ordenada. O usu�rio deve inserir um n�mero e o programa deve
        posicion�-lo no local correto para manter a ordem crescente.
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
    4. Lista Duplamente Encadeada - Remo��o
        Dada uma lista duplamente encadeada, implemente uma fun��o para remover
        um n� espec�fico e ajustar os ponteiros dos n�s vizinhos corretamente.
    */
    Dl.removeElement(11);

    Dl.print();

    return 0;
}
