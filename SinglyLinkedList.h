#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template<typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int list_size;

public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void push_back(const T& value);
    void insert(int index, const T& value);
    void erase(int index);
    int size() const;

    T operator[](int index) const;
    T& operator[](int index);

    void printList() const;
};

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void SinglyLinkedList<T>::push_back(const T& value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    list_size++;
}

template<typename T>
void SinglyLinkedList<T>::insert(int index, const T& value) {
    if (index < 0 || index > list_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* newNode = new Node(value);
    if (index == 0) {
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        if (!newNode->next) {
            tail = newNode;
        }
    }
    list_size++;
}

template<typename T>
void SinglyLinkedList<T>::erase(int index) {
    if (index < 0 || index >= list_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    if (index == 0) {
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete current;
    } else {
        Node* prev = nullptr;
        for (int i = 0; i < index; ++i) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        if (!current->next) {
            tail = prev;
        }
        delete current;
    }
    list_size--;
}

template<typename T>
int SinglyLinkedList<T>::size() const {
    return list_size;
}

template<typename T>
T SinglyLinkedList<T>::operator[](int index) const {
    if (index < 0 || index >= list_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
T& SinglyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= list_size) {
        throw std::out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

template<typename T>
void SinglyLinkedList<T>::printList() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << (current->next ? ", " : "\n");
        current = current->next;
    }
}

#endif // SINGLYLINKEDLIST_H
