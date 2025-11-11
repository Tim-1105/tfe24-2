#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP
#include <cstddef>
#include <stdexcept>
#include <algorithm>

namespace tfe24 {

template <typename T>

class myvector {

public:
myvector() noexcept
    : m_data(nullptr), m_size(0), m_capacity(0)
{}

explicit myvector(size_t count)
    : m_data(nullptr), m_size(0), m_capacity(0)
{ if (count > 0) {
       reserve(count);
       for (size_t i = 0; i < count; ++i) {
           m_data[i] = T();
       }
         m_size = count;
    }
}

~myvector() {
    delete[] m_data;
}

//Copy constructor

myvector(const myvector& other)
    : m_data(nullptr), m_size(other.m_size), m_capacity(other.m_capacity)
{   if (m_capacity > 0) {
        m_data = new T[m_capacity];
        copy_dyn_data(other.m_data, m_size);
    }
}

//Copy Zuweisungsoperator

myvector& operator= (const myvector& other) { 
    if (this == &other) return *this;
    T* newdata = nullptr;
    if (other.m_capacity > 0) {
        newdata = new T[other.m_capacity];
        for (size_t i = 0; i < other.m_size; ++i) {
            newdata[i] = other.m_data[i];
        }
    }
    delete[] m_data;

    m_data = newdata;
    m_size = other.m_size;
    m_capacity = other.m_capacity;
    return *this;
}

// Operator[]
T& operator[] (size_t index) {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}
// Const Operator[]
const T& operator[] (size_t index) const {
    if (index >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_data[index];
}

//Getter Methoden:
size_t capacity() const noexcept {
    return m_capacity;
}
size_t size() const noexcept {
    return m_size;
}

void reserve(size_t new_cap) {
    if (new_cap <= m_capacity) return;
    T* newdata = new T[new_cap];
    for (size_t i = 0; i < m_size; ++i) {
        newdata[i] = m_data[i];
    }
    delete[] m_data;
    m_data = newdata;
    m_capacity = new_cap;
}

//Pushback Methode

void push_back(const T& value) {
    if (m_size >= m_capacity) {
        size_t new_cap = (m_capacity == 0) ? 1 : m_capacity * 2;
        reserve(new_cap);
    }
    m_data[m_size] = value;
    ++m_size;
}

//Resize Methode
void resize (size_t new_size) {
    if (new_size > m_capacity) {
        reserve(new_size);
    }
    if (new_size > m_size) {
        for (size_t i = m_size; i < new_size; ++i) {
            m_data[i] = T();
        }
    }
    m_size = new_size;
}

//Clear Methode
void clear() noexcept {
    m_size = 0;
}

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
};

}

#endif /* MY_VECTOR_HPP */