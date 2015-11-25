#ifndef STACK_H
#define STACK_H

template <class a_type>
class DNode;

template <class Type>
class Stack {
    public:

        Stack();
        Stack(Type* data, int n);
        Stack(const Stack<Type>& rOther);
        ~Stack();
        Stack& operator=(const Stack<Type>& rOther);

        void            push(Type value);

        Type            pop();

        Type            peek() const;

        int             size() const;

        bool            isEmpty() const;

        void            print() const;

    protected:
        DNode<Type>*    m_pRoot;
        DNode<Type>*    m_pTop;
        int             m_size;
};

#include "Stack.hpp"

#endif
