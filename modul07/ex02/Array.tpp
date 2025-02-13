#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), size_(0) {}

template <typename T>
Array<T>::Array(size_t size) : size_(size) 
{
    data = new T[size_];
}

template <typename T>
Array<T>::Array(const Array& other) : size_(other.size_) 
{
    data = new T[size_];
    for (size_t i = 0; i < size_; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) 
{
    if (this != &other) 
    {
        delete[] data;
        size_ = other.size_;
        data = new T[size_];
        for (size_t i = 0; i < size_; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() 
{
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](size_t index) 
{
    if (index >= size_)
        throw ArrayException();
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const 
{
    if (index >= size_)
        throw ArrayException();
    return data[index];
}

template <typename T>
size_t Array<T>::size() const 
{
    return size_;
}

#endif
