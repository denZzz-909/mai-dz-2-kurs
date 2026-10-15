#include "dynamicArray.h"
#include <iostream>

int main() {
    intArray arr(10);

    arr.set(2, 28);
    arr.set(9, 11);
    arr.set(12, 34);
    arr.set(0, 101);
    arr.set(1, 15);

    arr.print();

    std::cout << arr.get(2) << " "
    << arr.get(3) << " "
    << arr.get(0) << " "
    << arr.get(50) << std::endl;

    intArray arr_n = arr;
    arr_n.set(2, 10);
    arr_n.set(3, 20);
    arr.print();
    arr_n.print();

    arr_n.append(14);
    arr_n.print();

    std::cout << "arr1 = arr1 + arr2: ";
    arr.add(arr_n);
    arr.print();

    std::cout << "arr2 = arr2 - arr1: ";
    arr_n.sub(arr);
    arr_n.print();

    return 0;
}