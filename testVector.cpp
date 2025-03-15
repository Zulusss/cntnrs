#include "testVector.h"

/*
IMPLEMENTATION FILE
*/
namespace s21{
template <typename T>
void Vector<T>::reserve_more_capacity(size_t size)
{
    if (size > m_capacity)
    {
        value_type *buff = new value_type[size];
        for (size_t i = 0; i < m_size; ++i)
            buff[i] = std::move(arr[i]);
        delete[] arr;
        arr = buff;
        m_capacity = size;
    }
}

// initializer list constructor (allows creating lists with initializer lists, see main.cpp)
template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> const &items)
{
    arr = new value_type[items.size()];
    int i = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        arr[i] = *it;
        i++;
    }
    m_size = items.size();
    m_capacity = items.size();
};

template <typename T>
size_t Vector<T>::size()
{
    return m_size;
}

template <typename T>
T Vector<T>::at(size_type i)
{  
    if (i >= m_size || m_size == 0) {
        throw std::out_of_range("Index out range");
    }
    return arr[i];
}

template <typename T>
void Vector<T>::push_back(T v)
{
    if (m_size == m_capacity)
    {
        reserve_more_capacity(m_size * 2);
    }
    arr[m_size++] = v;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& other) noexcept {
  if (this == &other) return *this;

  std::cout << "DArray move assigment" << std::endl;

  this->DeAlloc();

  m_size = other.m_size;
  m_capacity = other.m_capacity;
//   arr = other.arr;
  arr = std::move(other.arr);

  other.arr = nullptr;
  other.m_size = 0;
  other.m_capacity = 0;

  return *this;
}

// Copy assignment operator (deep copy)
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other) {
    if (this != &other) {
        delete[] arr;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        arr = new T[m_capacity];
        std::copy_n(other.arr, m_size, arr);
    }
    return *this;
}


template <typename T>
void Vector<T>::DeAlloc() {
  if (arr != nullptr) {
    delete [] arr;
    m_size = 0;
    m_capacity = 0;
    arr = nullptr;
  }
}

template <typename T>
void Vector<T>::pop_back(){
    if(m_size){
        m_size--;
    }
}

template <typename T>
void Vector<T>::Print(){
    for (size_t i = 0; i < this -> size(); i++) {
       std::cout << arr[i] << ' '; 
    }
    std::cout << std::endl;
}

template <typename T>
void Vector<T>::swap(Vector& other)
{
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
    std::swap(arr, other.arr);
}

    // First element. iterator
template <typename T>
T * Vector<T>::begin() const noexcept { return arr; }

  // One past the last element. iterator
template <typename T>
T * Vector<T>::end() noexcept { return begin() + size(); }

template <typename T>
void Vector<T>::erase(iterator pos){
    size_t index = std::distance(arr, pos);
    Vector<T> buff(m_size - index - 1);
        for (size_t i = index + 1, j = 0; i < m_size; ++i)
            buff[j++] = std::move(arr[i]);
        
        for (size_t i = index; i < m_size - 1; ++i)
            arr[i] = std::move(buff[i - index]);

    m_size--;
}

template <typename T>
T & Vector<T>::operator[](size_type pos){
    return arr[pos];
}

template <typename T>
T * Vector<T>::insert(iterator pos, const_reference value){
    size_t index = std::distance(arr, pos);
    Vector<T> buff(m_size + 1);
    for(size_t i = 0; i < index; i++)
        buff[i] = arr[i];
    
    buff[index] = value;

    for(size_t i = index + 1; i < m_size + 1; i++)
        buff[i] = arr[i - 1];
    
    this -> swap(buff);
    pos = this -> begin() + index;

    return pos;
}

template <typename T>
bool Vector<T>::empty(){
    bool res = true;
    if(this -> begin() != this -> end()) res = false;
    return res;
}

template <typename T>
size_t Vector<T>::max_size(){
    return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
    // return m_capacity;
}
//Same as reserve_more_capacity, which is private?
template <typename T>
void Vector<T>::reserve(size_t size){
    if(size > m_capacity){
    Vector<T> buff(size);
    for(size_t i = 0; i < m_size; i++)
        buff[i] = std::move(arr[i]);
    size_t tmp = this -> size();
    this -> swap(buff);
    m_size = tmp;
    }
}

template <typename T>
size_t Vector<T>::capacity(){
    return m_capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit(){
    if(m_size < m_capacity){
        m_capacity = m_size;
        // T* cut = this -> end();
        // delete [] cut;
        Vector<T> buff(m_size);
        for(size_t i = 0; i < m_size; i++)
            buff[i] = std::move(arr[i]);
        
        this -> swap(buff);
    }
}

template <typename T>
const T & Vector<T>::front(){
    return *begin();
}

template <typename T>
const T & Vector<T>::back(){
    return *(begin() + size() - 1);
}

template <typename T>
void Vector<T>::clear(){
    // Vector<T> empty(m_capacity);
    // empty.m_size = 0;
    // this -> swap(empty);
    this -> DeAlloc();
    m_size = 0;
    arr = nullptr;
}

template <typename T>
T* Vector<T>::data(){
    if(!this -> empty())
        return arr;
    else return nullptr;
}

// template <typename T>
// template <typename... Args>
// inline typename Vector<T>::iterator Vector<T>::insert_many(const_iterator pos,
//                                                        Args &&...args) {
//   Vector<value_type> tmp{args...};
//   iterator position = (iterator)pos;
//   for (size_t i = 0; i < tmp.size(); ++i) {
//     position = insert(position, tmp[i]) + 1;
//   }
//   return position;
// }

// template <typename T>
// template <typename... Args>
// inline void Vector<T>::insert_many_back(Args &&...args) {
// //   insert(this->end(), args...);
//   (this->push_back(std::forward<Args>(args)), ...);
// }
// template<typename T, typename... Args>
// template<typename T, typename... Targs>
// void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
// {
//     for (; *format != '\0'; format++)
//     {
//         if (*format == '%')
//         {
//             std::cout << value;
//             tprintf(format + 1, Fargs...); // recursive call
//             return;
//         }
//         std::cout << *format;
//     }
// }

// template <typename T>
// template <typename... Args>
// void vector<T>::insert_many_back(Args &&...args) {
//   insert_many(cend(), args...);
// }
// template <typename T, typename... Args>
// void  Vector<T>::insert_many_back(Args&&... args) {
//     // std::apply([&](auto... args) {
//     //     (this->push_back(args), ...);
//     // }, args);
//      (this->push_back(std::forward<Args>(args)), ...);
// }


// template <typename T, typename... Args>
// void Vector<T>::insert_many_back(Args&&... args){
//     for(int i = va_start; i < va_end; i++)
//         this -> push_back(args);
//     // va_start(args, T);
//     //  (this->push_back(std::forward_as_tuple(args)), ...); // C++17 feature for fold expression
//     //  (this->push_back(args), ...); // C++17 feature for fold expression
//     // (this->push_back(std::forward<T>(args)), ...);
// }
// externalizing template instances for correct linking, feel free to find more information
template class Vector<int>;
template class Vector<double>;
template class Vector<std::string>;
}