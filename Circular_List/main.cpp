#include <iostream>

#include "circularlist.h"

using namespace std;

int main()
{
    CircularList<int> cir;

    cir.append(1);
    cir.append(2);
    cir.append(3);
    cir.append(4);
    cir.append(5);
    cir.append(6);
    cir.append(7);
    cir.append(8);

    cir.print();

    cir.removeByStep(5);
    cir.print();
}
