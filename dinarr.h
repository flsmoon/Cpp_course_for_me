#ifndef DINARR_H
#define DINARR_H
#include <cstdint>
template <typename T>
class D{
    private:
        T* data;
        std::int64_t size=0;
        std::int64_t capacity=0;
    public:
        bool isEmpty(){
            return size==0;
        }
        D(std::int64_t cap);
        D(D& other);
        ~D();
        void clear();
        void increaseCap(std::int64_t cap);
        void decreaseCap(std::int64_t cap);
        void pushback(T x);
        void pushfront(T x);
        T max();
        T min();
        T sum();
        T front();
        T back();
        std::int64_t gsize() const;
        void insert(std::int64_t idx, T x);
        void del(std::int64_t idx);
        void eraseafter(std::int64_t idx);
        void printdata();
        T& operator[](std::int64_t idx);
        void printcap() const;
};
#endif 