#ifndef _VECTOR_H_
#define _VECTOR_H_

// TODO: implement assignment operator

namespace ctci {

template <class T>
class  vector {
    public:

        typedef T* iterator;
        typedef const T* const_iterator;

        vector();
        vector(unsigned int size);
        vector(unsigned int size, const T& initial);
        vector(const vector<T>& v);
        ~vector();

        unsigned int capacity() const;
        unsigned int size() const;
        bool empty() const;
        iterator begin();
        const_iterator const_begin();
        iterator end();
        const_iterator const_end();
        T& front();
        T& back();
        void push_back(const T& value);
        void pop_back();

        iterator erase(iterator it);

        void reserve(unsigned int capacity, T val = T());
        void resize(unsigned int size, T val = T());

        T& operator[](unsigned int index);
        T& operator[](unsigned int index) const;
        vector<T>& operator=(const vector<T>&);
        void clear();

    private:
        unsigned int my_size;
        unsigned int my_capacity;
        T* buffer;
};
}

#include "vector.hpp"

#endif
