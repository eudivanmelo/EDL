#include <iostream>
#include <string>
#include "stack.h"

using namespace std;

int main()
{
    Stack<char> charStack;

    string str = "Estrutura";

    for(char c: str){
        charStack.push(c);
    }

    charStack.print();

    return 0;
}
