#pragma once

class intDynamicArray {
    private:
        int* array;
        int size;
    public:
        intDynamicArray(int size);
        ~intDynamicArray();
        void print() const;
        int get(int index) const;
        int set(int index, int value);
}