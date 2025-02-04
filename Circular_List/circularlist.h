#ifndef CIRCULARLIST_H_INCLUDED
#define CIRCULARLIST_H_INCLUDED

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class CircularList{
private:
    Node<T>* head;

public:
    CircularList(){
        this->head = nullptr;
    }

    ~CircularList(){
        if (!head){
            delete head;
            return;
        }

        Node<T>* current = head->next;

        while(current != nullptr && current != head){
            Node<T>* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
    }

    void append(T value){
        Node<T>* item = new Node<T>{value, nullptr};

        if(!head){
            head = item;
            head->next = head;
            return;
        }

        Node<T>* current = head;
        while(current->next != head){
            current = current->next;
        }

        item->next = head;
        current->next = item;
    }

    void removeByStep(int step){
        if (!head){
            std::cout << "Lista vazia!" << std::endl;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        for(int i = 0; i < step; i++){
            previous = current;
            current = current->next;
        }

        if (previous == nullptr){
            Node<T>* last = head;
            while (last->next != head){
                last = last->next;
            }

            previous = last;
        }

        if (current == head){
             Node<T>* temp = head;
             head = head->next;
             previous->next = head;

             delete temp;
             return;
        }

        Node<T>* temp = current;
        previous->next = current->next;
        current = current->next;
        delete temp;
    }

    void print(){
        if (!head){
            std::cout << "A lista esta vazia!" << std::endl;
            return;
        }

        Node<T>* current = head;
        do{
            std::cout << current->data << " ";
            current = current->next;
        }while(current != head);

        std::cout << std::endl;
    }
};

#endif // CIRCULARLIST_H_INCLUDED
