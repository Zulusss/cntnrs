#ifndef TESTARRAY_H
#define TESTARRAY_H

#include <iostream>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <cstdarg>
#include <limits>

namespace s21{

template <class T, std::size_t N>

class Array
{

        // public attribures
    public:
        // member types
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;

    public:
        // default constructor (simplified syntax for assigning values to attributes)
        Array() : m_size(N) {};
        // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
        Array(std::initializer_list<value_type> const &items);
        // copy constructor with simplified syntax
        Array(const Array &v) {  for (size_type i = 0; i < m_size; ++i) {arr[i] = v.arr[i];}};
        // move constructor with simplified syntax
        Array(Array &&v) noexcept : Array(v) {};
     

        // destructor
        ~Array() {};

        size_type size();

        value_type at(size_type i);

        void swap(Array& other);
        Array& operator=(Array&& other) noexcept;
        Array& operator=(const Array& other);

        void Print();
        iterator begin();
        iterator end();

        reference operator[](size_type pos);

        bool empty();
        size_type max_size();

        const_reference front();
        const_reference back();

        T* data();
        void fill(const_reference value);
    private:
        size_type m_size = N;
        value_type arr[N];
};
} //s21_namespace
#endif

