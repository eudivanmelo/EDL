#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include <iostream>

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class Stack{
private:
    Node<T>* top;

public:
    Stack() : top(nullptr) {} // Constructor

    ~Stack() { // Destructor (important for memory management)
        while (top != nullptr) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void push(T value){
        Node<T>* item = new Node<T>{value, top};
        top = item;
    }

    void print(){
        if (!top){
            std::cout << "A lista esta vazia!" << std::endl;
            return;
        }

        Node<T>* current = top;
        while(current != nullptr){
            std::cout << current->data;
            current = current->next;
        };

        std::cout << std::endl;
    }
};

#endif // STACK_H_INCLUDED
