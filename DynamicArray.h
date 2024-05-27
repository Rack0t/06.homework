#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>
#include <iostream>

template<class T>
class DynamicArray {
public:
    DynamicArray(); // Конструктор по умолчанию
    DynamicArray(int initial_capacity); // Конструктор с заданным размером
    ~DynamicArray();

    void push_back(const T& value);
    void insert(int index, const T& value);
    void erase(int index);
    int size() const;

    T operator[](int index) const;
    T& operator[](int index);

private:
    void resize();

    T* m_data;
    int m_size;
    int m_capacity;
};

// Конструктор по умолчанию, использующий начальный размер 10
template<typename T>
DynamicArray<T>::DynamicArray() : DynamicArray(10) {}

// Конструктор с заданным размером
template<typename T>
DynamicArray<T>::DynamicArray(int initial_capacity) : m_size(0), m_capacity(initial_capacity) {
    if (initial_capacity <= 0) {
        throw std::invalid_argument("Initial capacity must be greater than zero");
    }
    m_data = new T[m_capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] m_data;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (m_size == m_capacity) {
        resize();
    }
    m_data[m_size++] = value;
}

template<typename T>
void DynamicArray<T>::insert(int index, const T& value) {
    if (index < 0 || index > m_size) {
        throw std::out_of_range("Index out of range");
    }
    if (m_size == m_capacity) {
        resize();
    }
    for (int i = m_size; i > index; --i) {
        m_data[i] = m_data[i - 1];
    }
    m_data[index] = value;
    ++m_size;
}

template<typename T>
void DynamicArray<T>::erase(int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }
    --m_size;
}

template<typename T>
int DynamicArray<T>::size() const {
    return m_size;
}

template<typename T>
T DynamicArray<T>::operator[](int index) const {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
T& DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

template<typename T>
void DynamicArray<T>::resize() {
    m_capacity *= 2;
    T* newData = new T[m_capacity];
    for (int i = 0; i < m_size; ++i) {
        newData[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newData;
}

template<typename T>
void printArray(const DynamicArray<T>& arr) {
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "\n" : ", ");
    }
}

#endif // DYNAMICARRAY_H
