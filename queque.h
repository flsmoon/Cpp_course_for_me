#ifndef QUEQUE_H
#define QUEQUE_H
#include <stdexcept>
#include <cstdint>
#include "stack.h"
template <typename T>
class Q{
    private:
        st<T> inst;
        st<T> outst;
        std::int64_t msize=0;
        void sh();
    public:
        Q(std::int64_t msize);
        ~Q();
        Q(Q<T>& other);
        bool isEmpty();
        std::int64_t size() const;
        void enqueue(T x);
        T dequeue();
        void printque();
};
#endif