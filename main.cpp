#include "DynamicArray.h"
#include "SinglyLinkedList.h"
#include "LinkedList.h"
#include <iostream>

int main() {

    // Создание массива с начальной емкостью по умолчанию (10)
    DynamicArray<int> d_arr(10);
    SinglyLinkedList<int> l_arr;
    LinkedList<int> tl_arr;
    for (int i = 0; i < 10; ++i) {
        d_arr.push_back(i);
        l_arr.push_back(i);
        tl_arr.push_bak(i);
    }

    tl_arr.printList();
    tl_arr.erase(2);
    tl_arr.erase(3);
    tl_arr.erase(10);
    tl_arr.printList();
    tl_arr.insert(0, 10);
    tl_arr.printList();
    tl_arr.insert(tl_arr.size()/2, 20);
    tl_arr.printList();
    tl_arr[8] = 30;
    tl_arr.printList();

    std::cout << std::endl;
    std::cout << "----- DynamicArray ------ " << std::endl;
    std::cout << std::endl;

    printArray(d_arr);
    std::cout << "Size: " << d_arr.size() << std::endl;

    d_arr.erase(2);
    d_arr.erase(3);
    d_arr.erase(4);
    printArray(d_arr);

    d_arr.insert(0, 10);
    printArray(d_arr);

    d_arr.insert(d_arr.size() / 2, 20);
    printArray(d_arr);

    d_arr.push_back(30);
    printArray(d_arr);

    // Создание массива с заданной начальной емкостью (20)
    DynamicArray<int> customArr(20);
    for (int i = 0; i < 10; ++i) {
        customArr.push_back(i);
    }

    std::cout << "Size: " << customArr.size() << std::endl;

    std::cout << std::endl;
    std::cout << "----- SingleLinkedListArray ------ " << std::endl;
    std::cout << std::endl;

    l_arr.printList();
    std::cout << "Size: " << l_arr.size() << std::endl;
    l_arr.erase(2);
    l_arr.erase(3);
    l_arr.erase(4);
    l_arr.printList();
    l_arr.insert(0, 10);
    l_arr.printList();
    l_arr.insert(l_arr.size() / 2, 20);
    l_arr.printList();
    l_arr.push_back(30);
    l_arr.printList();
    std::cout << "Size: " << l_arr.size() << std::endl;

    // Демонстрация перемещающего конструктора
    SinglyLinkedList<int> list2 = std::move(l_arr);
    list2.printList();

    // Демонстрация перемещающего оператора присваивания
    SinglyLinkedList<int> list3;
    list3 = std::move(list2);
    list3.printList();


    return 0;
}