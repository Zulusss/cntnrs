#include "testArray.h"

namespace s21{

// initializer list constructor (allows creating lists with initializer lists, see main.cpp)
template <typename T, size_t N>
array<T, N>::array(std::initializer_list<value_type> const &items) : array()
{
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
            arr[i++] = *it;

}

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::at(size_type i)
{  
    if (i >= m_size || m_size == 0) {
        throw std::out_of_range("Index out of range");
    }
    return arr[i];
}

template <typename T, size_t N>
array<T, N>& array<T, N>::operator=(array&& other) noexcept {
  if (this == &other) return *this;

    for(size_t i = 0; i < other.size(); i++)
        arr[i] = other.arr[i];

  return *this;
}

// Copy assignment operator (deep copy)
template <typename T, size_t N>
array<T, N>& array<T, N>::operator=(const array& other) {
    if (this != &other) {
        std::copy_n(other.arr, m_size, arr);
    }
    return *this;
}

template <typename T, size_t N>
void array<T, N>::Print(){
    for (size_t i = 0; i < this -> size(); i++) {
       std::cout << arr[i] << ' '; 
    }
    std::cout << std::endl;
}

template <typename T, size_t N>
void array<T, N>::swap(array& other)
{
  value_type tmp;
  for (size_type i = 0; i < other.size(); ++i) {
    tmp = other.arr[i];
    other.arr[i] = arr[i];
    arr[i] = tmp;
  }
}

// First element. iterator
template <typename T, size_t N>
T * array<T, N>::begin() { return arr; }

// One past the last element. iterator
template <typename T, size_t N>
T * array<T, N>::end() { return begin() + size(); }

template <typename T, size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos){
    return arr[pos];
}

template <typename T, size_t N>
bool array<T, N>::empty(){
    bool res = true;
    if(this -> begin() != this -> end()) res = false;
    return res;
}

template <typename T, size_t N>
inline typename array<T, N>::size_type array<T, N>::size()
{
    return m_size;
}

template <typename T, size_t N>
typename array<T, N>::size_type array<T, N>::max_size(){
    return size();
}

template <typename T, size_t N>
typename array<T, N>::const_reference array<T, N>::front(){
    return *begin();
}

template <typename T,  size_t N>
typename array<T, N>::const_reference array<T, N>::back(){
    return *(begin() + size() - 1);
}

template <typename T, size_t N>
T* array<T, N>::data(){
    if(!this -> empty())
        return arr;
    else return nullptr;
}

template <typename T, size_t N>
void array<T, N>::fill(const_reference value){
    for (size_type i = 0; i < m_size; ++i) {
        arr[i] = value;
  }    
}

// externalizing template instances for correct linking, feel free to find more information
template class array<int, 4>;
template class array<double, 4>;
template class array<std::string, 4>;
template class array<int, 5>;
template class array<double, 5>;
template class array<std::string, 5>;
template class array<int, 0>;
template class array<double, 0>;
template class array<std::string, 0>;
} //s21_namespace