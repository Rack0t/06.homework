#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template<class T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int list_size;
public:
    LinkedList();
    ~LinkedList();

    void push_bak(const T& value);
    void insert(int index, const T& value);
    void erase(int index);
    int size() const;

    T operator[](int index) const;
    T& operator[](int index);

    void printList() const;
};

template<typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), list_size(0) {}

template<typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current){
        Node* next = current->next;
        delete current;
        current = next;
    }
}
template<typename T>
void LinkedList<T>::push_bak(const T &value) {
    Node* newNode = new Node(value);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    list_size++;
}

template<typename T>
void LinkedList<T>::insert(int index, const T &value) {
    if (index < 0 || index > list_size){
        throw std::out_of_range("Index out of range");
    }
    Node* newNode = new Node(value);
    if (index == 0){
        newNode->next = head;
        if (head){
            head->prev = newNode;
        }
        head = newNode;
        if (!tail) {
            tail = newNode;
        }
    } else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i ){
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        if (current->next) {
            current->next->prev = newNode;
        }
        current->next = newNode;
        if (!newNode->next){
            tail = newNode;
        }
    }
    list_size++;
}

template<typename T>
void LinkedList<T>::erase(int index) {
    if (index < 0 || index > list_size) {
        throw std::out_of_range("Index out of range");
    }
    Node *current = head;
    if (index == 0) {
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete current;
    } else {
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        current->prev->next = current->prev;
        if (current->next){
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }
        delete current;
    }
    list_size--;
}

template<typename T>
int LinkedList<T>::size() const {
    return list_size;
}

template<typename T>
T LinkedList<T>::operator[](int index) const {
    if (index < 0 || index > list_size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}
template<typename T>

T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index > list_size) {
        throw std::out_of_range("Index out of range");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    return current->data;
}

/*
template<typename T>
void LinkedList<T>::printList() const {
    Node* current = head;
    while (current){
        std::cout << current->data << (current->next ? ", " : "\n");
        current = current->next;
    }
}
*/

#endif // LINKEDLIST_H
