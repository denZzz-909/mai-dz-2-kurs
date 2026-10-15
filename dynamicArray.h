#pragma once

class intArray {
    private:
        int* array;
        int size;
    public:
        intArray(int size);
        intArray(const intArray& new); // конструктор копирования

        ~intArray();

        void print() const;
        void set(int index, int value);
        int get(int index) const;
};