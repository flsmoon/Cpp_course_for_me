#ifndef STACK_H
#define STACK_H
#include <cstdint>
#include "dinarr.h"
template <typename T>
class st{
    private:
        D<T> data;
        std::int64_t msize=0;
    public:
        st(std::int64_t msize);
        ~st();
        st(st<T>& other);
        bool isEmpty();
        void push(T x);
        T top();
        T pop();
        std::int64_t size() const;
        T& operator[](std::int64_t idx);
        void printst();
};
#endif

