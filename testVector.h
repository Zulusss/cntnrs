#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include <iostream>
#include <initializer_list>
#include <utility>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <cstdarg>
#include <limits>
// #include <variadic.h>

/*
HEADER FILE
*/
namespace s21{
// Test vector class with some basic example operations and concepts
template <class T>
// template <typename T, typename... Args>
class Vector
{
    // private attributes
    private:
        size_t m_size;
        size_t m_capacity;
        T *arr;
        // public attribures
    public:
        // member types
        using value_type = T;
        using reference = T &;
        using const_reference = const T &;
        using iterator = T *;
        using const_iterator = const T *;
        using size_type = size_t;
        // private method
    private:
        void reserve_more_capacity(size_type size);
        // public methods
    public:
        // default constructor (simplified syntax for assigning values to attributes)
        Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}
        // parametrized constructor for fixed size vector (explicit was used in order to
        // avoid automatic type conversion)
        explicit Vector(size_type n) : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {}
        // initializer list constructor (allows creating lists with initializer lists, see main.cpp)
        Vector(std::initializer_list<value_type> const &items);
        // copy constructor with simplified syntax
        Vector(const Vector &v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {};
        // move constructor with simplified syntax
        Vector(Vector &&v) : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr)
        {
            v.arr = nullptr;
            v.m_size = 0;
            v.m_capacity = 0;
        }

        // destructor
        ~Vector() { delete[] arr; }

        // some method examples
        // size getter
        size_type size();
        // element accessor
        value_type at(size_type i);
        // append new element
        void push_back(value_type v);
        void pop_back();
        void swap(Vector& other);
        Vector& operator=(Vector&& other) noexcept;
        Vector& operator=(const Vector& other);
        void DeAlloc();
        void Print();
        iterator begin() const noexcept;
        iterator end() noexcept;
        void erase(iterator pos);
        reference operator[](size_type pos);
        iterator insert(iterator pos, const_reference value);
        bool empty();
        size_type max_size();
        void reserve(size_type size);
        size_type capacity();
        void shrink_to_fit();
        const_reference front();
        const_reference back();
        void clear();
        T* data();
public:
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
// template <typename T, typename... Args>
// void insert_many_back(Args&&... args) {
//     (this->push_back(std::forward_as_tuple(args)), ...);
// }
        // template <typename T>
        // template <typename U, typename... Args>

        // template <typename Args>  // inner template param
// void insert_many_back(U&& arg1, Args&&... args)
//  {
//         // (this->push_back(std::forward<U>(arg1)), ...); // C++17 feature for fold expression
// (this->push_back(std::forward<U>(arg1)), );
//     // Use a loop to call push_back for each remaining argument
//     ((void)std::initializer_list<int>{{}}[0], this->push_back(std::forward<Args>(args)))...
//     // (this->push_back(std::forward<U>(arg1)), (this->push_back(std::forward<Args>(args))), ...);
// };
    // template <typename T, typename... Args>
    // void  insert_many_back(Args&&... args) {
//     // std::apply([&](auto... args) {
//     //     (this->push_back(args), ...);
//     // }, args);
//      (this->push_back(std::forward<Args>(args)), ...);
// };
//   template <typename... Args>
//   void insert_many_back(Args &&...args);
//   template <typename T>
// template <typename... Args>
// void Vector<T>::insert_many_back(T&& arg1, Args&&... args) {
//     this->push_back(arg1);
//     (this->push_back(std::forward_as_tuple(args)), ...);
// }
// inline void vector<T>::insert_many_back(Args &&...args) {
// //   emplace(this->end(), args...);
//   (this->push_back(std::forward_as_tuple(args)), ...);
// }
        // void insert_many_back(Args&&... args);
        // template <typename T, typename... Args>
// void insert_many_back(T&&... args){
//     // for(int i = va_start; i < va_end; i++)
//     //     this -> push_back(args);
//     // va_start(args, T);
//     //  (this->push_back(std::forward_as_tuple(args)), ...); // C++17 feature for fold expression
//     //  (this->push_back(args), ...); // C++17 feature for fold expression
//     // (this->push_back(std::forward<T>(args)), ...);
//     std::initializer_list<T> list = {(T)arg for arg in {args}};
//     this->insert(this->end(), list);
// }
//   template <typename... Args>
//   iterator insert_many(const_iterator pos, Args &&...args);
//   template <typename... Args>
//   void insert_many_back(Args &&...args);
// // template <typename T>
// template <typename... Args>
// typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
//                                                     Args &&...args) {
//   vector<value_type> tmp{args...};
//   iterator cur_pos = begin() + (pos - cbegin());
//   for (size_t i = 0; i < tmp.size(); ++i) {
//     cur_pos = insert(cur_pos, tmp[i]);
//     ++cur_pos;
//   }
//   return cur_pos;
// }
// // template <typename T>
// template <typename... Args>
// void vector<T>::insert_many_back(Args &&...args) {
//   insert_many(cend(), args...);
// }


};

template <typename T>
template <typename... Args>
inline typename Vector<T>::iterator Vector<T>::insert_many(const_iterator pos,
                                                       Args &&...args) {
  Vector<value_type> tmp{args...};
  iterator position = (iterator)pos;
  for (size_t i = 0; i < tmp.size(); ++i) {
    position = insert(position, tmp[i]) + 1;
  }
  return position;
}

template <typename T>
template <typename... Args>
inline void Vector<T>::insert_many_back(Args &&...args) {
  // insert(this->end(), args...);
  (this->push_back(std::forward<Args>(args)), ...);
}
}
#endif

