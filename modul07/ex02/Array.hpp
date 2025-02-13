#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception> 

template <typename T>
class Array 
{
    private:
        T* data;
        size_t size_;

    public:

        Array();
        Array(size_t size);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();

        T& operator[](size_t index);
        const T& operator[](size_t index) const;
        size_t size() const;

        // ✅ Özel hata sınıfı
        class ArrayException : public std::exception {
        public:
            const char* what() const throw() {
                return "Array index out of bounds!";
            }
        };
};

#include "Array.tpp"

#endif
