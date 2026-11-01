#include "dynamicArray.h"
#include <iostream>

int main() {
    intArray arr(10);

    arr.set(2, 28);
    arr.set(4, 20);
    arr.set(9, 11);
    arr.set(1, 15);
    arr.set(7, 89);

    std::cout << "array of ten objects:\n";
    arr.print();

    std::cout << "printing some indexes: ";
    std::cout << arr.get(2) << " "
    << arr.get(3) << " "
    << arr.get(0) << std::endl;

    intArray arr_n = arr;
    arr_n.set(2, 10);
    arr_n.set(3, 20);
    std::cout << "original array:\n";
    arr.print();
    std::cout << "copied and changed array:\n";
    arr_n.print();

    arr_n.append(14);
    std::cout << "adding an element to the back:\n";
    arr_n.print();

    std::cout << "arr1 = arr1 + arr2: ";
    arr.add(arr_n);
    arr.print();

    std::cout << "arr2 = arr2 - arr1: ";
    arr_n.sub(arr);
    arr_n.print();


    try { // setter
        std::cout << "setter with an out of range index: ";
        arr.set(12, 34);
    } catch (const std::out_of_range& err) {std::cout << "out_of_range: " << err.what() << std::endl;}
    try {
        std::cout << "setter with an invalid value: ";
        arr.set(0, 101);
    } catch (const std::invalid_argument& err) {std::cout << "exceeding_value: " << err.what() << std::endl;}
    try { // getter
        std::cout << "getter with an out of range index: ";
        arr.get(50);
    } catch (const std::out_of_range& err) {std::cout << "out_of_range: " << err.what() << std::endl;}
    try { // constructor
        std::cout << "invalid range constructor: ";
        intArray arr_test(-1000);
    } catch (const std::out_of_range& err) {std::cout << "out_of_range: " << err.what() << std::endl;}
    try { // append
        std::cout << "invalid value append: ";
        arr.append(10000);
    } catch (const std::invalid_argument& err) {std::cout << "exceeding_value: " << err.what() << std::endl;}

    return 0;
}