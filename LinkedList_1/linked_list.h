#ifndef LINKED_LIST_H_INCLUDED
#define LINKED_LIST_H_INCLUDED

#include <iostream>

template <typename T>
struct Node {
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedList{
private:
    Node<T>* head;

public:
    LinkedList(){
        this->head = nullptr;
    }

    ~LinkedList(){
        while(head){
            Node<T>* temp = head;
            head = head->next;

            delete temp;
        }
    }

    void insertOnBegin(T value){
        Node<T>* item = new Node<T>{value, head};

        head = item;
    }

    void insertOnEnd(T value){
        Node<T>* item = new Node<T>{value, nullptr};

        if (!head){
            head = item;
            return;
        }

        Node<T>* current = head;
        while(current->next != nullptr){
            current = current->next;
        }

        current->next = item;
    }

    Node<T>* findElement(T value){
        if (!head){
            std::cout << "Lista esta vazia!" << std::endl;
            return nullptr;
        }

        Node<T>* current = head;
        while(current != nullptr){
            if (current->data == value){
                return current;
            }

            current = current->next;
        }

        std::cout << "Nenhum elemento encontrado!" << std::endl;
        return nullptr;
    }

    void removeElement(T value){
        if (!head){
            std::cout << "Lista esta vazia!" << std::endl;
            return;
        }

        if (head->data == value){
            head = head->next;
            return;
        }

        Node<T>* current = head;
        while(current->next != nullptr){
            if (current->next->data == value){
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }

            current = current->next;
        }
    }

    void removeDuplicates(){
        Node<T>* x = head;

        while(x != nullptr){
            Node<T>* y = x->next;
            Node<T>* prev_y = x;

            while(y != nullptr){
                if (x->data == y->data){
                    Node<T>* temp = y;
                    y = y->next;

                    prev_y->next = y;
                    delete temp;

                } else {
                    prev_y = y;
                    y = y->next;
                }
            }
            x = x->next;
        }
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

#endif // LINKED_LIST_H_INCLUDED
