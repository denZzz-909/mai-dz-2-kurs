#pragma once

class intArray {
    private:
        int* array;
        int size;
    public:
        intArray(int size);
        ~intArray();

        intArray(const intArray& copied); // задание 2: конструктор копирования

        void print() const;
        void set(int index, int value);
        int get(int index) const;

        void append(int value); // задание 3: добавление в конец

        void add(const intArray& added); // задание 4: сложение и вычитание массивов
        void sub(const intArray& subtracted);
};