#ifndef STACK_H
#define STACK_H

#include <string>
#include <stdexcept>

class Stack {
    private:
        char* items;
        int top;
        int max_size;

    public:
        Stack(int size);

        ~Stack();

        void append(char value);

        char pop();
        char peek();

        int count();
        void clear();
        bool isEmpty();
        std::string toString();
};

#endif