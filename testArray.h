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

class array
{

protected:
        struct ArrayIterator;
        struct ArrayConstIterator;
      
public:
        // member types
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;
        
protected:
        size_type m_size = N;
        value_type arr[N];

public:
// array Member functions
        // default constructor (simplified syntax for assigning values to attributes)
        array() : m_size(N) {};
        // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
        array(std::initializer_list<value_type> const &items);
        // copy constructor with simplified syntax
        array(const array &a) {  for (size_type i = 0; i < m_size; ++i) {arr[i] = a.arr[i];}};
        // move constructor with simplified syntax
        array(array &&a) noexcept : array(a) {};
     

        // destructor
        ~array() {};

        array& operator=(array&& other) noexcept;
        array& operator=(const array& other);

// array Element access
        reference at(size_type i);
        reference operator[](size_type pos);
        const_reference front();
        const_reference back();
        T* data();

// array Iterators
        iterator begin();
        iterator end();

// array Capacity
        bool empty();
        size_type size();
        size_type max_size();

// array Modifiers

        void swap(array& other);
        void fill(const_reference value);
//other
        void Print();
};

template <typename T, std::size_t N>
struct array<T, N>::ArrayIterator {
 protected:
  T* ptr_{nullptr};

  ArrayIterator();
  ArrayIterator(T* ptr) : ptr_(ptr) {}

  reference operator*() { return *ptr_; }
  ArrayIterator& operator++() {
    ++ptr_;
    return *this;
  }

  ArrayIterator& operator--() {
    --ptr_;
    return *this;
  }

  bool operator==(const ArrayIterator& other) const {
    return ptr_ == other.ptr_;
  }
  bool operator!=(const ArrayIterator& other) const {
    return ptr_ != other.ptr_;
  }
  // ptrdiff_t operator-(const VectorIterator& other) const;
};

template <typename T, std::size_t N>
struct array<T, N>::ArrayConstIterator : public ArrayIterator {
  ArrayConstIterator();
  ArrayConstIterator(T* ptr) : ArrayIterator(ptr) {}

  const_reference operator*() { return *ArrayIterator::ptr_; }
};

} //s21_namespace
#endif

