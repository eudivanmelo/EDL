#ifndef DOUBLYLINKEDLIST_H_INCLUDED
#define DOUBLYLINKEDLIST_H_INCLUDED

#include<iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* previous;
    Node<T>* next;
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;

public:
    DoublyLinkedList(){
        this->head = nullptr;
    }

    ~DoublyLinkedList(){
        while(head){
            Node<T>* temp = head;
            head = head->next;

            delete temp;
        }
    }

    void append(T value){
        Node<T>* item = new Node<T>{value, nullptr, nullptr};

        if (!head){
            head = item;
            return;
        }

        Node<T>* current = head;
        Node<T>* previous = nullptr;

        while(current != nullptr && current->data < value){
            previous = current;
            current = current->next;
        }

        item->next = current;
        item->previous = previous;

        if (previous == nullptr) {
            head = item;
        } else {
            previous->next = item;
        }

        if (current != nullptr) {
            current->previous = item;
        }
    }

    void removeElement(T value){
        if (!head){
            std::cout << "Lista vazia!" << std::endl;
            return;
        }

        Node<T>* current = head;
        while(current != nullptr && current->data != value){
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Elemento não encontrado!" << std::endl;
            return;
        }

        if (current == head) {
            head = current->next;
            if (head != nullptr) {
                head->previous = nullptr;
        }
        } else {
            if (current->next != nullptr) {
                current->next->previous = current->previous;
            }
            current->previous->next = current->next;
        }

        delete current;
    }

    void print(){
        if (!head){
            std::cout << "A lista esta vazia!" << std::endl;
            return;
        }

        Node<T>* current = head;
        while(current != nullptr){
            std::cout << current->data << " ";
            current = current->next;
        }

        std::cout << std::endl;
    }
};

#endif // DOUBLYLINKEDLIST_H_INCLUDED
