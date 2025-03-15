#include "testArray.h"

/*
IMPLEMENTATION FILE
*/
namespace s21{

// initializer list constructor (allows creating lists with initializer lists, see main.cpp)
template <typename T, size_t N>
Array<T, N>::Array(std::initializer_list<value_type> const &items) : Array()
{
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
            arr[i++] = *it;

}


template <typename T, size_t N>
T Array<T, N>::at(size_type i)
{  
    if (i >= m_size || m_size == 0) {
        throw std::out_of_range("Index out of range");
    }
    return arr[i];
}

template <typename T, size_t N>
inline typename Array<T, N>::size_type Array<T, N>::size()
{
    return m_size;
}

template <typename T, size_t N>
Array<T, N>& Array<T, N>::operator=(Array&& other) noexcept {
  if (this == &other) return *this;

    for(size_t i = 0; i < other.size(); i++)
        arr[i] = other.arr[i];

  return *this;
}

// Copy assignment operator (deep copy)
template <typename T, size_t N>
Array<T, N>& Array<T, N>::operator=(const Array& other) {
    if (this != &other) {
        std::copy_n(other.arr, m_size, arr);
    }
    return *this;
}


template <typename T, size_t N>
void Array<T, N>::Print(){
    for (size_t i = 0; i < this -> size(); i++) {
       std::cout << arr[i] << ' '; 
    }
    std::cout << std::endl;
}

template <typename T, size_t N>
void Array<T, N>::swap(Array& other)
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
T * Array<T, N>::begin() { return arr; }

  // One past the last element. iterator
template <typename T, size_t N>
T * Array<T, N>::end() { return begin() + size(); }


template <typename T, size_t N>
T & Array<T, N>::operator[](size_type pos){
    return arr[pos];
}


template <typename T, size_t N>
bool Array<T, N>::empty(){
    bool res = true;
    if(this -> begin() != this -> end()) res = false;
    return res;
}

template <typename T, size_t N>
size_t Array<T, N>::max_size(){
    return size();
}

template <typename T, size_t N>
const T & Array<T, N>::front(){
    return *begin();
}

template <typename T,  size_t N>
const T & Array<T, N>::back(){
    return *(begin() + size() - 1);
}

template <typename T, size_t N>
T* Array<T, N>::data(){
    if(!this -> empty())
        return arr;
    else return nullptr;//std::string = "empty"
}

template <typename T, size_t N>
void Array<T, N>::fill(const_reference value){
    for (size_type i = 0; i < m_size; ++i) {
        arr[i] = value;
  }    
}

// externalizing template instances for correct linking, feel free to find more information
template class Array<int, 4>;
template class Array<double, 4>;
template class Array<std::string, 4>;
template class Array<int, 5>;
template class Array<double, 5>;
template class Array<std::string, 5>;
template class Array<int, 0>;
template class Array<double, 0>;
template class Array<std::string, 0>;
} //s21_namespace