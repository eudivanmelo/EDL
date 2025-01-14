#include "../include/stack.h"

Stack::Stack(int size)
{
    max_size = size;
    top = -1;
    items = new char[size];
}

Stack::~Stack()
{
    delete[] items;
}

void Stack::append(char value)
{
    if ((top + 1) >= max_size)
    {
        throw std::overflow_error("Overflow: não é possível adicionar item a uma pilha cheia.");
        return;
    }

    top++;
    items[top] = value;
}

char Stack::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Underflow: não é possível remover item de uma lista vazia.");
        return ' ';
    }

    return items[top--];
}

char Stack::peek(){
    if (isEmpty())
    {
        return ' ';
    }

    return items[top];
}

int Stack::count() {
    return (top + 1);
}

void Stack::clear(){
    top = -1;
}

bool Stack::isEmpty(){
    return (top == -1);
}

std::string Stack::toString(){
    std::string s = "";

    for (int i = 0; i <= top; i++){
        s += items[i];

        if (i < top){
            s += ", ";
        }
    }

    return s;
}