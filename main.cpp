#include "dynamicArray.h"
#include <iostream>

int main() {

    Array<int> arr(15), arr1(15);

    for (int i = 0; i<15; ++i) {
        arr[i] = i + 10;
    }

    std::cout << "first array: " << arr << std::endl;

    for (int i = 0; i<15; ++i) {
        arr1[i] = i + 20;
    }

    std::cout << "second array: " << arr1 << std::endl;

    std::cout << "array distance: " << arr.dist(arr1) << std::endl;


    // intArray arr(10);

    // arr.set(2, 28);
    // arr.set(4, 20);
    // arr.set(9, 11);
    // arr.set(1, 15);
    // arr.set(7, 89);

    // std::cout << "array of ten objects:\n";
    // arr.print();

    // std::cout << "printing some indexes: ";
    // std::cout << arr.get(2) << " "
    // << arr.get(3) << " "
    // << arr.get(0) << std::endl;

    // intArray arr_n = arr;
    // arr_n.set(2, 10);
    // arr_n.set(3, 20);
    // std::cout << "original array:\n";
    // arr.print();
    // std::cout << "copied and changed array:\n";
    // arr_n.print();

    // arr_n.append(14);
    // std::cout << "adding an element to the back:\n";
    // arr_n.print();

    // std::cout << "arr1 = arr1 + arr2: ";
    // arr.add(arr_n);
    // arr.print();

    // std::cout << "arr2 = arr2 - arr1: ";
    // arr_n.sub(arr);
    // arr_n.print();

    return 0;
}